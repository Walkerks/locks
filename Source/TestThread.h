#include <thread>
#include "Counter.h"
class TestThread :public std::thread{

	private:
	static int ID_GEN;
	static int MAX_COUNT;

	Counter counter;
	int id;
public:
	//TestThread();
	TestThread(Counter counter) : thread() {
		id = ID_GEN++;
		this->counter = counter;
	}

	void run() {
		for (int i = 0; i<MAX_COUNT; i++)
			counter.getAndIncrement();
	}

	int getThreadId(){
		return id;
	}
};

