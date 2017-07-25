#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 2048

#define err(info) do { \
	printf("%s\n", info); \
	exit(1); \
} while(0) \

int main()
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;

		if ((pid = fork()) < 0) {
			err("fork error");
		} else if (pid == 0) { /* child */
			execlp(buf, buf, (char *)0);
			err("error execlp");
			exit(127);
		}

		/* parent */
		if ((pid = waitpid(pid, &status, 0)) < 0)
			err("waitpid error");
		printf("%% ");
	}
	exit(0);
}