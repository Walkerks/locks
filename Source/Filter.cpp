#include "Filter.h"

Filter::Filter(){
	Filter(2);
}


Filter::Filter(const size_t numThreads){
	level = new size_t[numThreads];
	victim = new size_t[numThreads];
	levelSize = numThreads;
	for (size_t i = 0; i < numThreads; level[i++] = 0);
}


void Filter::lock(size_t id){
	for (size_t i = 1; i < levelSize; i++){
		level[id] = i;
		victim[i] = id;
		bool found = false;
		do{
			for (size_t k = 0; k<levelSize; k++)
				if (k != id && (found = (level[k] >= i && victim[i] == id)))
					break;
		} while (found);
	}
}

void Filter::unlock(size_t id){
	level[id] = 0;
}