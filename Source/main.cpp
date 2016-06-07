
#include <pthread.h>
#include "LockTwo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//#include <iostream>

lock_t myLock;
#define         NUMTHREADS    2

void * criticalSection(void * arg){
	//fprintf(stdout, "fooo");
	//lock(&myLock);
	int i = 0;
	while(true){
	    lock(&myLock);
        fprintf(stdout, "thread %u \n", pthread_self());
        fprintf(stdout, "a");
        fprintf(stdout, "b");
        fprintf(stdout, "c");
        fprintf(stdout, "d");
        fprintf(stdout, "e\n");
        unlock(&myLock);
        //usleep(rand() % 100);
	}
	//
}



int main(){
//	thrd_t thread1;
	lock_init(&myLock, NUMTHREADS);
	pthread_t thread;
    pthread_create(&thread, NULL, criticalSection, NULL);


	while(true){
	    lock(&myLock);
        fprintf(stdout, "thread %u \n", pthread_self());
        fprintf(stdout, "1");
        fprintf(stdout, "2");
        fprintf(stdout, "3");
        fprintf(stdout, "4");
        fprintf(stdout, "5\n");
        unlock(&myLock);
        //usleep(rand() % 100);
	}

	pthread_join(thread, NULL);
	return 0;
}
