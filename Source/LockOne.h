#include "Lock.h"
#include <stdlib.h>
#include <stdbool.h>
#include "tinycthread.h"
//proto of the lock
typedef struct {
	thrd_t firstThread;
	bool flag[2];
} lock_t;
/*
private boolean[] flag = new boolean[2];

@Override
public void lock() {
	int i = ((TestThread)Thread.currentThread()).getThreadId();
	int j = 1 - i;
	flag[i] = true;
	while (flag[j]);
	//			System.out.println("Thread " + i + " waiting");
}

@Override
public void unlock() {
	int i = ((TestThread)Thread.currentThread()).getThreadId();
	flag[i] = false;
}
*/

void lock_init(lock_t *myLock){
	myLock->firstThread = thrd_current();
	myLock->flag[0] = false;
	myLock->flag[1] = false;
}

void lock(lock_t *myLock){
	int j;
	if (myLock->firstThread == thrd_current()){
		j = 0;
	}
	else{
		j = 1;
	}
	while (myLock->flag[j]);
}

void unlock(lock_t *myLock){
	int j;
	if (myLock->firstThread == thrd_current()){
		j = 0;
	}
	else{
		j = 1;
	}
	myLock->flag[j] = false;
}
