#include <stdio.h>
/*
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/sendfile.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <glob.h>
#include <errno.h>
*/
#define _GNU_SOURCE         /* See feature_test_macros(7) */
//#include <sched.h>

void __stack_chk_fail(void)
{
	printf("__stack_chk_fail\n");
}

