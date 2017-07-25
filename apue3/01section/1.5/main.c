#include <unistd.h> // read write STDIN_FILENO STDOUT_FILENO
#include <stdlib.h> // exit
#include <stdio.h>	// printf
#define BUFFSIZE 4096

int main()
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	{
		if (write(STDOUT_FILENO, buf, n) != n)
			printf("write error\n");
	}

	if (n < 0)
		printf("read error");

	exit(0);
}