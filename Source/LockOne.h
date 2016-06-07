#include "Lock.h"
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
//proto of the lock
typedef struct {
	volatile pthread_t firstThread;
	volatile bool flag[2];
	int numThreads;
} lock_t;

void lock_init(lock_t *myLock, int numThreads){
	myLock->firstThread = pthread_self();
	myLock->flag[0] = false;
	myLock->flag[1] = false;
	myLock->numThreads = numThreads;
}

void lock(lock_t *myLock){
	int curId, i;
	if (myLock->firstThread == pthread_self()){
		curId = 0;
		i = 1;
	}
	else{
		curId = 1;
		i = 0;
	}
	myLock->flag[curId] = true;
	while (myLock->flag[i]);
}

void unlock(lock_t *myLock){
	int curId;
	if (myLock->firstThread == pthread_self()){
		curId = 0;
	}
	else{
		curId = 1;
	}
	myLock->flag[curId] = false;
}
