#include <stdio.h>
#include <stdlib.h>
//#include <pcre.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/sendfile.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <glob.h>
#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <sched.h>
#include <crypt.h>

void __stack_chk_fail(void)
{
}

int * __errno_location(void)
{
	return (int*)0xFBFBFBFBFBFB;
}

//pcre_malloc = malloc;

/*
accept4
*/
char *crypt_r(const char *key, const char *salt,
              struct crypt_data *data)
{
	return NULL;
}

int __fxstat64(int ver, int fildes, struct stat64 * stat_buf)
{
	return 0;
}

/*
pcre *pcre_compile(const char *pattern, int options, const char **errptr, int *erroffset, const unsigned char *tableptr)
{
	return NULL;
}

int pcre_fullinfo(const pcre *code, const pcre_extra *extra, int what, void *where)
{
	return -90;
}

int pcre_config(int what, void *where)
{
	return 0;
}

int pcre_exec(const pcre *code, const pcre_extra *extra, const char *subject, int length, int startoffset, int options, int *ovector, int ovecsize)
{
	return 0;
}

void pcre_free_study(pcre_extra *extra)
{
}


pcre_extra *pcre_study(const pcre *code, int options, const char **errptr)
{
	return NULL;
}
*/

int posix_fadvise64(int fd, off_t offset, off_t len, int advice)
{
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
	return 0;
}

int sigemptyset(sigset_t *set)
{
	return 0;
}

/* files */

int open64(const char *pathname, int flags, ...)
{
	return -1;
}

int openat64(int dirfd, const char *pathname, int flags, ...)
{
	return -1;
}

int fcntl64(int fd, int cmd, ... /* arg */ )
{
	return -1;
}

int __xstat64(int ver, const char * path, struct stat64 * stat_buf)
{
	printf("__xstat64 is missing\n");
	return 0;
}

int __lxstat64(int ver, const char * path, struct stat64 * stat_buf)
{
	printf("__lxstat64 is missing\n");
	return -1;
}

int __fxstatat64(int ver, int dirfd, const char * path, struct stat64 * stat_buf, int flags)
{
	printf("__fxstatat64 is missing\n");
	return -1;
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
	printf("statfs is missing\n");
	return -1;
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
