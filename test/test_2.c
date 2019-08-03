#include "malloc.h"

int main()
{
	int i;
	char *addr;

	i = 1;
	while (i < 10)
	{
		addr = (char*)malloc(i);
		addr[0] = 42;
		free(addr);
		i++;
	}
	i = 1;
	while (i < 10)
	{
		addr = (char*)malloc(i);
		addr[0] = 42;
		free(addr);
		i++;
	}
	show_alloc_mem();
	return (0);
}
