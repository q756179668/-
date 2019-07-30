#include <iostream>
#include <thread>
#include<windows.h>

using namespace std;

void doSomething(int i,int j){
	cout << "Info-------:child-" << i << "----"<<j<<endl;
}

struct func
{
	int& i;
	func(int& i_) :i(i_){}
	void operator() ()
	{
		for (unsigned j = 0; j < 100; j++){
			doSomething(i,j);
		}
		Sleep(500);
	}
};

void oops(int i){
	//static int some_local_state = 0;
	func my_func(i);
	std::thread my_thread(my_func);
	my_thread.detach();

}

int main(){
	int i = 0;
	while (true){
		
		oops(++i);
		cout << "Info-------:main" << endl;
		Sleep(2000);
	}
	return 0;
}