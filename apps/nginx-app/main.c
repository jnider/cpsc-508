#include <stdio.h>

/* Import user configuration: */
#include <uk/config.h>

int main(int argc, char *argv[])
{
	printf("Hello NGInx!\n");

	nginx_main(argc, argv);
}
