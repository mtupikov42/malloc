#include <stdlib.h>

int main()
{
	void *a = malloc(1024);
	a = malloc(1024 * 32);
	a = malloc(1024 * 1024);
	a = malloc(1024 * 1024 * 16);
	a = malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return (0);
}
