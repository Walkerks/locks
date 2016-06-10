#include "Lock.h"
#include <stdlib.h>
#include <stdbool.h>
#include <thread>

#ifndef _TWOLOCK_LOCK_
#define _TWOLOCK_LOCK_

class LockTwo : public Lock{
private:
	volatile size_t victim;
public:
	//LockTwo();
	//~LockTwo();
	void lock(size_t id);
	void unlock(size_t id);

};

#endif
