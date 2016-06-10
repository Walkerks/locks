#include "Peterson.h"

Peterson::Peterson(){
	firstThread = std::this_thread::get_id().hash();
	flag[0] = false;
	flag[1] = false;
	//victim = nullptr;
}
void Peterson::lock(size_t id){
	size_t  i = std::this_thread::get_id().hash();
	int curId, j;
	if (firstThread == i){
		curId = 0;
		j = 1;
	}
	else{
		curId = 1;
		j = 0;
	}
	flag[curId] = true;
	victim = i;
	while (flag[j] && victim == i);
	
}
void Peterson::unlock(size_t id){
	int curId;
	if (firstThread == std::this_thread::get_id().hash()){
		curId = 0;
	}
	else{
		curId = 1;
	}
	flag[curId] = false;
}