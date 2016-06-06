
#include "tinycthread.h"
#include "LockOne.h"
#include <stdio.h>
#include <stdlib.h>
//#include <iostream>

lock_t myLock;

int criticalSection(void * arg){
	//fprintf(stdout, "fooo");
	lock(&myLock);
	fprintf(stdout, "thread %u", thrd_current());
	unlock(&myLock);
	return 0;
}


int main(){
	thrd_t thread1;
	lock_init(&myLock);
	int a = 0;
	thrd_create(&thread1, criticalSection, NULL);
	lock(&myLock);
	fprintf(stdout, "thread %u", thrd_current());
	unlock(&myLock);

	return 0;
}