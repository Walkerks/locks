#include "Lock.h"
#include <stdlib.h>
#include <stdbool.h>
#include <thread>
//#include <pthread.h>


#ifndef _ONELOCK_LOCK_
#define _ONELOCK_LOCK_

class LockOne : public Lock{
private:
	volatile bool flag[2];
public:
	LockOne();
	void lock(size_t id);
	void unlock(size_t id);

};

#endif
