#include "Lock.h"
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
//proto of the lock
typedef struct {
    volatile pthread_t victim;
	volatile pthread_t firstThread;
	volatile int level;
	volatile bool flag[2];
	int numThreads;
} lock_t;


void lock_init(lock_t *myLock, int numThreads){
    myLock->numThreads = numThreads;
}

void lock(lock_t *myLock){
pthread_id_np_t   tid;
tid = pthread_getthreadid_np();

}

void unlock(lock_t *myLock){

}

/*
package edu.vt.ece.locks;

import edu.vt.ece.bench.TestThread;

public class Filter implements Lock{
	private volatile int[] level;
	private volatile int[] victim;

	public Filter() {
		this(2);
	}

	public Filter(int n){
		level = new int[n];
		victim = new int[n];
		for(int i=0; i<n; level[i++]=0);
	}

	@Override
	public void lock() {
		int me = ((TestThread)Thread.currentThread()).getThreadId();
		for(int i=1; i<level.length; i++){
			level[me] = i;
			victim[i] = me;
			boolean found = false;
			do{
				for(int k=0; k<level.length; k++)
					if(k!=me && (found = (level[k] >= i && victim[i] == me)))
						break;
			}while(found);
		}
	}

	@Override
	public void unlock() {
		int me = ((TestThread)Thread.currentThread()).getThreadId();
		level[me] = 0;
	}

}

*/
