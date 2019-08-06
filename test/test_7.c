#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	if (argc == 2) {
		srand(time(NULL));
		long int size = atol(argv[1]);
		char* str = (char*)malloc(size);
		if (str)
			printf("malloc done.\n");
		else {
			printf("malloc failed (NULL).\n");
			return -1;
		}

		for (int i = 0; i < size; i++)
		{
			str[i] = rand() % 128;
			if (i < 100)
				write(1, &str[i], 1);
		}
	}
	return 0;
}