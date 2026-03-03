#ifndef CALLS_H_SENTRY
#define CALLS_H_SENTRY

int sys_read(int fd, void *buf, int size);
int sys_write(int fd, const void *buf, int size);
void sys_exit(int code_exit);
extern int sys_errno;

#endif
