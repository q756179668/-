#include<iostream>
#include<math.h>

using namespace std;

void put(int start,int end ,int t,int n){
	if (t <= end){
		long result = end - t + 1;
		cout << result << endl;
	}
	else{
		start = end + 1;
		end = start + pow(2, n) * 3 - 1;
		put(start,end,t,n+1);
	}
}

int main(){

	int t;
	while (cin >> t){
		
		int n = 0;
		int start = 1;
		int end = 3;
		put(1,3,t,1);
	} //while (getchar() != EOF);

	return 0;
}