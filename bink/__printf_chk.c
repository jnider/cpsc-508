#include <stdio.h>

int __printf_chk(int __flag, const char *__restrict __format, ...)
{
	return printf("__printf_chk\n");
}

