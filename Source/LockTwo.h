#include "Lock.h"
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
//proto of the lock
typedef struct {
	volatile pthread_t victim;
	int numThreads;
} lock_t;
/*
private volatile int victim;

	@Override
	public void lock() {
		int i = ((TestThread)Thread.currentThread()).getThreadId();
		victim = i;
		while(victim == i);
//			System.out.println("Thread " + i + " waiting");
	}

	@Override
	public void unlock() {}


*/

void lock_init(lock_t *myLock,  int numThreads){
    myLock->numThreads = numThreads;
}

void lock(lock_t *myLock){
    pthread_t  i = pthread_self();
    myLock->victim = i;
    while(myLock->victim == i);
}

void unlock(lock_t *myLock){

}
