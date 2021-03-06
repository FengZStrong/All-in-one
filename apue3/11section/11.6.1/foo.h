#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

struct foo
{
	int f_count;
	pthread_mutex_t f_lock;
	int f_id;
};

struct foo* foo_alloc(int id)
{
	struct foo *fp = NULL;
	if ((fp = (struct foo*)malloc(sizeof(struct foo))) != NULL) {
		fp->f_count = 1;
		fp->f_id = id;
		if (pthread_mutex_init(&fp->f_lock, NULL) != 0) {
			free(fp);
			fp = NULL;
			return NULL;
		}
	}

	return fp;
}

void foo_hold(struct foo *fp)
{
	pthread_mutex_lock(&fp->f_lock);
	++(fp->f_count);
	printf("foo_hold:%d\n", fp->f_count);
	pthread_mutex_unlock(&fp->f_lock);
}

void foo_rele(struct foo *fp)
{
	pthread_mutex_lock(&fp->f_lock);
	if (--(fp->f_count) == 0) {
		pthread_mutex_unlock(&fp->f_lock);
		pthread_mutex_destroy(&fp->f_lock);
		free(fp);
		fp = NULL;
		printf("free\n");
	}
	else {
		printf("foo_rele:%d\n", fp->f_count);
		pthread_mutex_unlock(&fp->f_lock);
	}
}