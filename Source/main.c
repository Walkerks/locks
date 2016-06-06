
#include "tinycthread.h"
#include <pthread.h>
#include "LockOne.h"
#include <stdio.h>
#include <stdlib.h>
//#include <iostream>

lock_t myLock;

void * criticalSection(void * arg){
	//fprintf(stdout, "fooo");
	//lock(&myLock);
	fprintf(stdout, "thread %u \n", pthread_self());
	//unlock(&myLock);
}


int main(){
//	thrd_t thread1;
	lock_init(&myLock);
	pthread_t thread;
	int a = 0;
	volatile int i = 0; 

	for(a = 0; a < 10000; a++){
//	thrd_create(&thread1, criticalSection, NULL);
	pthread_create(&thread, NULL, criticalSection, NULL);
	//lock(&myLock);
	for(i = 0; i < 1000000; i++){
	}
	fprintf(stdout, "thread %u \n", pthread_self());

	//unlock(&myLock);
	pthread_join(thread, NULL);
	}
	return 0;
}
