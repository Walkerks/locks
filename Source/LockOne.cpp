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
	firstThread = std::this_thread::get_id();
}
void LockOne::lock(size_t id){
	//int i = this->thread::get_id();
	int i, curId;
	if (firstThread == std::this_thread::get_id()){
		curId = 0;
		i = 1;
	}
	else{
		curId = 1;
		i = 0;
	}
	flag[curId] = true;
	while (flag[i]);
}

void LockOne::unlock(size_t id){
	int curId;
	if (firstThread == std::this_thread::get_id()){
		curId = 0;
	}
	else{
		curId = 1;
	}
	flag[curId] = false;
}
