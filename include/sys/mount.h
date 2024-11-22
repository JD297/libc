#ifndef JD297_LIBC_SYS_MOUNT_H
#define JD297_LIBC_SYS_MOUNT_H

extern int mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data);

extern int umount2(const char *target, int flags);
#endif
