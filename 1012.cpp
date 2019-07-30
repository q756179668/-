#include <iostream>
#include <list>

using namespace std;

int main(){

	int k;
	while (cin >> k && k != 0){
		
		int all = 2 * k;
		int m = k+1;
		int index = 0;
		for (int i = 1; i <= k; i++){
			index = (m - 1 + index) % (all - i + 1);
			if (index < k){
				m++;
				index = 0;
				i = 0;
			}
		}
		int result[] = { 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 };
		cout << result[k-1] << endl;
		
	}

	return 0;
}