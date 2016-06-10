#include "LockOne.h"
#include <thread>

/*
void LockOne::lock_init(lock_t *myLock, int numThreads){
myLock->firstThread = pthread_self();
myLock->flag[0] = false;
myLock->flag[1] = false;
myLock->numThreads = numThreads;
}
*/


LockOne::LockOne(){
	flag[0] = false;
	flag[1] = false;
}
void LockOne::lock(size_t id){
	int j = 1 - id;
	if (id == 0){
		volatile int a = 0;
	}
	else{
		volatile int a = 0;
	}
	flag[id] = true;
	while (flag[j]);
}

void LockOne::unlock(size_t id){
	flag[id] = false;
}
