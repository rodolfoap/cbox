#include<iostream>
#include<thread>
#include<mutex>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

std::mutex m;
void mutex_print(int namei){
	m.lock();
	std::cerr<<namei<<':';
	m.unlock();
}

void counter1(int name){ for(int i=0; i<1000; i++) mutex_print(name+i); }
void counter2(int name){ for(int i=0; i<1000; i++) mutex_print(name+i); }

int main(){
	// Each function is copied to a different memory area
	std::thread t1=std::thread(counter1, 1000);
	std::thread t2=std::thread(counter2, 2000);
	t1.join();
	t2.join();
	return 0;
}
