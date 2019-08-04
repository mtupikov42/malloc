#include "malloc.h"

int main()
{
	int i;
	char *addr;

	i = 0;
	while (i < 1024)
	{
		i++;
	}
	show_alloc_mem();
	return (0);
}
