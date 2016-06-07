#include "Lock.h"
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdatomic.h>
//proto of the lock
typedef struct {
	volatile pthread_t victim;
	volatile pthread_t firstThread;
	volatile bool flag[2];
	int numThreads;
} lock_t;


void lock_init(lock_t *myLock,  int numThreads){
	myLock->firstThread = pthread_self();
	myLock->flag[0] = false;
	myLock->flag[1] = false;
	myLock->numThreads = numThreads;
}

void lock(lock_t *myLock){
    pthread_t  i = pthread_self();
    int j, curId;
	if (myLock->firstThread == i){
		curId = 0;
		i = 1;
	}
	else{
		curId = 1;
		i = 0;
	}
	myLock->flag[curId] = true;
	myLock->victim = i;
	while (myLock->flag[i] && myLock->victim == i);

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

int getThreadId(pthread_t * thread){


}


