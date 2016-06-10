
#include "Lock.h"
#include "LockOne.h"
#include "LockTwo.h"
#include "Peterson.h"
#include "Filter.h"
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <ctime>

typedef enum {ONE, TWO, PETERSON, FILTER} locks;

//#define			LOCKTYPE	FILTER
#define         MAXNUMTHREADS    16
#define			MAXCOUNT	1000000

Lock * getLock(locks l, int threds){
	switch (l)
	{
	case ONE:
		return new LockOne;
		break;
	case TWO:
		return new LockTwo;
		break;
	case PETERSON:
		return new Peterson;
		break;
	case FILTER:
		return new Filter(threds);
		break;
	default:
		return new Filter(threds);
		break;
	}
}

Lock * myLock;// = getLock();
int counter = 0;

void criticalSection(int id){
		//std::cout << id << "\n";
		for (int i = 0; i < MAXCOUNT; i++){
			myLock->lock(id);
			counter++;
			myLock->unlock(id);
		}
		//std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
	//	return;

}





int main(){
	std::thread thrs[MAXNUMTHREADS];
	std::clock_t start;
	double executionTime;
	
	for (int l = ONE; l <= FILTER; l++){
		if (l == TWO){
			l++;
		}
		
		for (int numThreads = 2; numThreads <= MAXNUMTHREADS; numThreads = numThreads + 2){
			myLock = getLock(static_cast<locks>(l), numThreads);
			start = std::clock();
			for (int i = 0; i < numThreads; i++){
				thrs[i] = std::thread(criticalSection, i);
			}
			for (int i = 0; i < numThreads; i++){
				if (thrs[i].joinable()){
					thrs[i].join();
				}
			}
			executionTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			std::cout << "lockType " << l << " with " << numThreads << " Threads took " << executionTime << "Seconds \n";
			delete myLock; 
			myLock = nullptr;
			if (l == ONE || l == TWO || l == PETERSON){
				break;
			}
		}

	}

	//std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));

	return 0;
}
