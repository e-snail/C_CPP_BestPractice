#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>

pthread_mutex_t count_lock;
pthread_cond_t count_nonzero;
unsigned count;

pthread_t thread[2];

void *decrement_count()
{
	pthread_mutex_lock (&count_lock);
	while(count==0) 
		pthread_cond_wait( &count_nonzero, &count_lock);
	count=count -1;
	printf("decrement_count: count = %d\n", count);
	pthread_mutex_unlock (&count_lock);
}

void *increment_count()
{
	pthread_mutex_lock(&count_lock);
	if(count==0)
		pthread_cond_signal(&count_nonzero);
	count=count+1;
	printf("increment_count: count = %d\n", count);
	pthread_mutex_unlock(&count_lock);
}

void thread_create(void)
{
    int temp;
    memset(&thread, 0, sizeof(thread));          //comment1
    /*创建线程*/
    if((temp = pthread_create(&thread[0], NULL, increment_count, NULL)) != 0)       //comment2
        printf("线程1创建失败!\n");
    else
        printf("线程1被创建\n");

    if((temp = pthread_create(&thread[1], NULL, decrement_count, NULL)) != 0)  //comment3
        printf("线程2创建失败");
    else
        printf("线程2被创建\n");
}

void thread_wait(void)
{
     /*等待线程结束*/
     if(thread[0] != 0) {                   //comment4
         pthread_join(thread[0],NULL);
         printf("线程1已经结束\n");
     }

     if(thread[1] != 0) {                //comment5
         pthread_join(thread[1],NULL);
         printf("线程2已经结束\n");
     }
}



int main()
{
	thread_create();
	thread_wait();
	return 0;
}
