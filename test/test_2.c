#include "malloc.h"

int main()
{
	int i;
	char *addr;

	i = 0;
	while (i < 1000)
	{
		addr = (char*)malloc(i);
		free(addr);
		i++;
	}

	show_alloc_mem();
	return (0);
}
