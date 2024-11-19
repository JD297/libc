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
CCFLAGS		= -Wall -Wextra -Wpedantic -nostdlib -W -ffreestanding
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
