#include<iostream>
#include<vector>

using namespace std;

int main(){


	int p, e, i, d, Case = 1;
	while (cin >> p >> e >> i >> d){
		 if (p == -1 && e == -1 && i == -1 && d == -1) break;
		 int da = (5544 * p + 14421 * e + 1288 * i - d + 21252) % 21252;
		 if (da == 0)
		      cout << "Case " << Case++ << ": the next triple peak occurs in 21252 days." << endl;
		  else
			  cout << "Case " << Case++ << ": the next triple peak occurs in " << da << " days." << endl;
	}

	return 0;
}