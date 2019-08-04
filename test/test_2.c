#include "malloc.h"

int main()
{
	int i;
	void *addr1 = malloc(5);
	void *addr2 = malloc(123);
	void *addr3 = malloc(12);
	void *addr4 = malloc(56);
	void *addr5 = malloc(84);
	void *addr6 = malloc(122);
	void *addr7 = malloc(35);
	show_alloc_mem();
	free(addr1);
	free(addr2);
	free(addr3);
	free(addr4);
	free(addr5);
	free(addr6);
	free(addr7);
	show_alloc_mem();
	addr1 = malloc(5);
	addr2 = malloc(123);
	addr3 = malloc(12);
	addr4 = malloc(56);
	addr5 = malloc(84);
	addr6 = malloc(122);
	addr7 = malloc(35);
	show_alloc_mem();
	return (0);
}
