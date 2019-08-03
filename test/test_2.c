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
		show_alloc_mem();
		i++;
	}
	return (0);
}
