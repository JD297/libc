PREFIX		= /usr/local
LIBDIR		= $(PREFIX)/lib
MANDIR		= $(PREFIX)/share/man
INCLUDEDIR	= $(PREFIX)/include

TARGET		= libc.so
TARGETDIR	= lib
SRCDIR		= src
SRCINCLUDEDIR	= include
BUILDDIR	= build
SRC_FILES	= $(wildcard $(SRCDIR)/*.c)
OBJ_FILES	= $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRC_FILES))

CC		= gcc
CCFLAGS		= -Wall -Wextra -Wpedantic -nostdlib -W -ffreestanding -g
CCINCLUDE	= -I $(SRCINCLUDEDIR)

$(TARGET): clean $(OBJ_FILES)
	$(CC) $(CCFLAGS) -shared $(OBJ_FILES) -o $(TARGETDIR)/$(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CCINCLUDE) $(CCFLAGS) -fpic -c -o $@ $<

clean:
	rm -f $(BUILDDIR)/*.o $(TARGETDIR)/$(TARGET)

install: $(TARGET)
	cp $(TARGETDIR)/$(TARGET) $(LIBDIR)/$(TARGET)
	cd $(SRCINCLUDEDIR) && find -iname "*.h" -exec cp --parents "{}" ../$(INCLUDEDIR) \;

uninstall:
	rm -f $(LIBDIR)/$(TARGET)
	rm -rf $(INCLUDEDIR)

TEST_BINDIR	= tests/bin
TEST_SRCDIR	= tests/src
TEST_SRCFILES	= $(wildcard $(TEST_SRCDIR)/*.c)
TEST_TARGETS	= $(patsubst $(TEST_SRCDIR)/%.c,%,$(TEST_SRCFILES))

TEST_CCFLAGS	= -nodefaultlibs -W -ffreestanding -g

tests: $(TARGET) $(TEST_TARGETS)
	tests/run.sh

%: $(TEST_SRCDIR)/%.c
	$(CC) $(CCINCLUDE) $(TEST_CCFLAGS) -DTARGET=\"$@\" -o $(TEST_BINDIR)/$@ $< -L$(TARGETDIR) -l:$(TARGET)
	$(CC) -DTARGET=\"$@\" -o $(TEST_BINDIR)/expc_$@ $<
