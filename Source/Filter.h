#include "Lock.h"
#include <stdlib.h>
#include <stdbool.h>
#include <thread>
#include <vector>

#ifndef _FILTERLOCK_LOCK_
#define _FILTERLOCK_LOCK_

class Filter : public Lock{
private:
	volatile size_t *level;
	volatile size_t *victim;
	size_t levelSize;

public:
	Filter();
	Filter(size_t numThreads);
	void lock(size_t id);
	void unlock(size_t id);
};

#endif
