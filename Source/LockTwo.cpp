#include "LockTwo.h"
#include <thread>

LockTwo::LockTwo(){
	//victim = nullptr;
}
LockTwo::~LockTwo(){
	/*if (victim != nullptr){
		delete victim;
		victim = nullptr;
	}*/
}
void LockTwo::lock(size_t id){
	victim = id;
	while (victim == id);
}

void LockTwo::unlock(size_t id){
	//No real need
}
	