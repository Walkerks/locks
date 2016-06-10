#include "Lock.h"
#include <stdlib.h>
#include <stdbool.h>
#include <thread>

#ifndef _PETERSONLOCK_LOCK_
#define _PETERSONLOCK_LOCK_

class Peterson : public Lock{
private:
	volatile size_t victim;
	volatile size_t firstThread;
	volatile bool flag[2];
	
public:
	Peterson();
	void lock(size_t id);
	void unlock(size_t id);
};

#endif



