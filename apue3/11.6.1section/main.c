#include "foo.h"
#include <stdio.h>

void* handle_f(void *p)
{
	printf("handle_f start.\n");
	struct foo *data = (struct foo*)p;
	while (1)
	{
		foo_hold(data);
	}

	pthread_exit((void*)1);
	return NULL;
}

void* release_f(void *p)
{
	printf("release_f start.\n");
	struct foo *data = (struct foo*)p;
	while (1)
	{
		foo_rele(data);
	}
	pthread_exit((void*)2);
	return NULL;
}

int main()
{
	struct foo *data = 	foo_alloc(1);

	pthread_t pid_h;
	pthread_create(&pid_h, NULL, handle_f, (void*)data);
	sleep(1);
	pthread_t pid_r;
	pthread_create(&pid_r, NULL, release_f, (void*)data);

	void *exit1 = NULL;
	pthread_join(pid_h, &exit1);
	printf("thread %d exit:%ld.", pid_h, (long)exit1);
	exit(0);

	void *exit2 = NULL;
	pthread_join(pid_r, &exit2);
	printf("thread %d exit:%ld.", pid_r, (long)exit2);
}