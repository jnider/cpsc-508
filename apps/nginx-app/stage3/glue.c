#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/sendfile.h>
#include <sys/utsname.h>
#include <sys/socket.h>
#include <sys/vfs.h>    /* or <sys/statfs.h> */
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <glob.h>
#include <errno.h>
#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <sched.h>

/* network */
uint32_t ntohl(uint32_t h)
{
	return 0;
}

uint16_t ntohs(uint16_t h)
{
	return 0;
}

uint32_t htonl(uint32_t h)
{
	return 0;
}

uint16_t htons(uint16_t h)
{
	return 0;
}

/* compiler */
void __stack_chk_fail(void)
{
}

int * __errno_location(void)
{
	printf("Emulating __errno_location: %p\n", &errno);
	return &errno;
}

int stat64(const char *pathname, struct stat *statbuf)
{
	return stat(pathname, statbuf);
}

int fstat64(int fd, struct stat *statbuf)
{
	return fstat(fd, statbuf);
}

int lstat64(const char *pathname, struct stat *statbuf)
{
	return lstat(pathname, statbuf);
}

int fstatat64(int dirfd, const char *pathname, struct stat *statbuf, int flags)
{
	return fstatat(dirfd, pathname, statbuf, flags);
}

int __fxstat64(int ver, int fildes, struct stat * stat_buf)
{
	//return fstat(ver, fildes, stat_buf);
	return -1;
}

int __fxstatat64(int ver, int dirfd, const char * path, struct stat * stat_buf, int flags)
{
	//return __fxstatat(ver, dirfd, path, stat_buf, flags);
	return -1;
}

int posix_fadvise64(int fd, off_t offset, off_t len, int advice)
{
	printf("posix_fadvise64 is missing\n");
	return 0;
}

int sched_setaffinity(pid_t pid, size_t cpusetsize,
                      cpu_set_t *mask)
{
	printf("sched_setaffinity is missing\n");
	return -1;
}

/* signals */
int sigaddset(sigset_t *set, int signum)
{
	printf("sigaddset is missing\n");
	return 0;
}

int sigemptyset(sigset_t *set)
{
	printf("sigemptyset is missing\n");
	return 0;
}

/* files */

int open64(const char *pathname, int flags, ...)
{
	printf("open64 is missing\n");
	return -1;
}

int openat64(int dirfd, const char *pathname, int flags, ...)
{
	printf("openat64 is missing\n");
	return -1;
}

int fcntl64(int fd, int cmd, ... /* arg */ )
{
	printf("fcntl64 is missing\n");
	return -1;
}

int __xstat64(int ver, const char * path, struct stat * stat_buf)
{
	return __xstat(ver, path, stat_buf);
}

int __lxstat64(int ver, const char * path, struct stat * stat_buf)
{
	return __lxstat(ver, path, stat_buf);
}

char * __realpath_chk(const char * path, char * resolved_path, size_t resolved_len)
{
	printf("__realpath_chk is missing\n");
	return NULL;
}

ssize_t sendfile64(int out_fd, int in_fd, off_t * offset, size_t count)
{
	printf("sendfile64 is missing\n");
	return 0;
}

ssize_t pread64(int fd, void *buf, size_t count, off_t offset)
{
	printf("pread64 is missing\n");
	return 0;
}

ssize_t pwrite64(int fd, const void *buf, size_t count, off_t offset)
{
	printf("pwrite64 is missing\n");
	return 0;
}

ssize_t pwritev64 (int fd, const struct iovec *vector, int count, off_t offset)
{
	printf("pwritev64 is missing\n");
	return 0;
}

int ftruncate64(int fd, off_t length)
{
	printf("ftruncate is missing\n");
	return 0;
}

int statfs64(const char *path, struct statfs *buf)
{
	return statfs(path, buf);
}

/* mm */
void *mmap64(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset)
{
	printf("mmap is missing\n");
	return NULL;
}

/* string */
void * __memcpy_chk(void * dest, const void * src, size_t len, size_t destlen)
{
	printf("__memcpy_chk is missing\n");
	return NULL;
}

void * __memmove_chk(void * dest, const void * src, size_t len, size_t destlen)
{
	printf("__memmove_chk is missing\n");
	return NULL;
}

/* epoll */
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event)
{
	printf("epoll_ctl is missing\n");
	return 0;
}

int epoll_wait(int epfd, struct epoll_event *events,
                      int maxevents, int timeout)
{
	printf("epoll_wait is missing\n");
	return 0;
}

int epoll_create(int size)
{
	printf("epoll_create is missing\n");
	return -1;
}

/* limits */
int getrlimit64(int resource, struct rlimit *rlim)
{
	printf("getrlimit is missing\n");
	return -1;
}

int setrlimit64(int resource, const struct rlimit *rlim)
{
	printf("setrlimit is missing\n");
	return -1;
}

/* sockets */
int accept4(int sockfd, struct sockaddr *addr, socklen_t *addrlen, int flags)
{
	printf("accept4 is missing\n");
	return -1;
}

/* glob */
int glob64(const char * pattern, int flags, int (*errfunc) (const char *, int), glob_t * pglob)
{
	printf("glob64 is missing\n");
	return -1;
}

void globfree64(glob_t * pglob)
{
	printf("globfree64 is missing\n");
}

/* eventfd */
int eventfd(unsigned int initval, int flags)
{
	printf("eventfd is missing\n");
	return -1;
}

/* host stuff */
int gethostname(char *name, size_t len)
{
	strncpy(name, "joelhost", len);
	return 0;
}

int uname(struct utsname *buf)
{
	printf("uname\n");
	return -1;
}

int getpagesize(void)
{
	return 4096;
}

long int
__fdelt_chk (long int d)
{
/*
  if (d < 0 || d >= FD_SETSIZE)
    __chk_fail ();

  return d / __NFDBITS;
*/
	printf("__fdelt_chk is missing\n");
	return -1;
}

/* borrowed from glibc printf_chk.c
int
___printf_chk (int flag, const char *format, ...)
{
  va_list ap;
  int done;

  _IO_acquire_lock_clear_flags2 (stdout);
  if (flag > 0)
    stdout->_flags2 |= _IO_FLAGS2_FORTIFY;

  va_start (ap, format);
  done = vfprintf (stdout, format, ap);
  va_end (ap);

  if (flag > 0)
    stdout->_flags2 &= ~_IO_FLAGS2_FORTIFY;
  _IO_release_lock (stdout);

  return done;
}
*/

long sysconf(int name)
{
	printf("sysconf\n");
	return 0;
}

long syscall(long number, ...)
{
	printf("syscall %li\n", number);
	return 0;
}

/* networking */
struct cmsghdr *
__cmsg_nxthdr (struct msghdr *mhdr, struct cmsghdr *cmsg)
{
  if ((size_t) cmsg->cmsg_len < sizeof (struct cmsghdr))
    /* The kernel header does this so there may be a reason.  */
    return NULL;

  cmsg = (struct cmsghdr *) ((unsigned char *) cmsg
			     + CMSG_ALIGN (cmsg->cmsg_len));
  if ((unsigned char *) (cmsg + 1) > ((unsigned char *) mhdr->msg_control
				      + mhdr->msg_controllen)
      || ((unsigned char *) cmsg + CMSG_ALIGN (cmsg->cmsg_len)
	  > ((unsigned char *) mhdr->msg_control + mhdr->msg_controllen)))
    /* No more entries.  */
    return NULL;
  return cmsg;
}
