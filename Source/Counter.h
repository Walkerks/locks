
class Counter {
private:
	int value;
public:
	Counter(){
		value = 0;
	}
	Counter(int c){
		value = c;
	}
	int getAndIncrement(){
		int temp = value;
		value = temp + 1;
		return temp;
	}
	/*
	public String toString() {
		return String.valueOf(value);
	
	}*/
};
