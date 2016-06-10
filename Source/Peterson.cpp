#include "Peterson.h"

Peterson::Peterson(){
	firstThread = std::this_thread::get_id().hash();
	flag[0] = false;
	flag[1] = false;
	//victim = nullptr;
}
void Peterson::lock(size_t id){
	int j = 1 - id;
	flag[id] = true;
	victim = id;
	while (flag[j] && victim == id);
	
}
void Peterson::unlock(size_t id){
	flag[id] = false;
}