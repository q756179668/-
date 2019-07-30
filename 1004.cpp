#include <iostream>

using namespace std;

int main(){
	double sum = 0;
	for (int i = 0; i < 12 ; i++ ){
		double everyMonth;
		cin >> everyMonth;
		sum += everyMonth;
	}
	printf("$%.2f\r\n", (double)(sum / 12));
	return 0;
}