
#ifndef _LOCK_LOCK_
#define _LOCK_LOCK_
//proto of the lock
class Lock{
public:
	virtual void lock(size_t id) = 0;
	virtual void unlock(size_t id) = 0;

};

#endif