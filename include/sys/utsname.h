#ifndef JD297_LIBC_SYS_UTSNAME
#define JD297_LIBC_SYS_UTSNAME

#define _UTSNAME_LENGTH 65

typedef struct utsname {
	char sysname[_UTSNAME_LENGTH + 1];
	char nodename[_UTSNAME_LENGTH + 1];
	char release[_UTSNAME_LENGTH + 1];
	char version[_UTSNAME_LENGTH + 1];
	char machine[_UTSNAME_LENGTH + 1];
	//char domainname[_UTSNAME_LENGTH];
};

#endif
