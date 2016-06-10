#include "TestThread.h"

int TestThread::ID_GEN = 0;
int TestThread::MAX_COUNT = 1000;

/*/
TestThread::TestThread(){

}*/
TestThread::TestThread(Counter counter){
	id = ID_GEN++;
	this->counter = counter;
}

void TestThread::run() {
	for (int i = 0; i<MAX_COUNT; i++)
		counter.getAndIncrement();
}

int TestThread::getThreadId(){
	return id;
}