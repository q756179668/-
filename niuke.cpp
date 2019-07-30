#include <iostream>
#include<math.h>


using namespace std;

bool isPrime(int i)
{
	bool isPrime = true;
	//除到i的平方根就可以判断
	for (int j = 2; j <= sqrt(i); j++)
	{
		if (i%j == 0)
			isPrime = false;
	}
	return isPrime;
}

int main() {
	int n;
	cin >> n;


	int PriNum = 0;
	for (int i = 2; i <= n; i++){
		if (isPrime(i)){
			PriNum++;
		}
	}

	int result = PriNum*pow(2, PriNum-1);
	cout << result << endl;

	return 0;
}