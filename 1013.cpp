#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	//while (cin >> n){
		bool allCoin[12];
		memset(allCoin, false, sizeof(bool)* 12);

		int countCoin[12] = { 0 };
		string op[3][3];
		int N = 3;

		for (int i = 0; i < N;i++){
			cin >> op[i][0] >> op[i][1] >> op[i][2];
		}
		for (int i = 0; i < N; i++){
			if (op[i][2] == "up"){
				for (int j = 0; j < op[i][0].size(); j++){
					countCoin[(int)(op[i][0][j] - 'A')]++;
					
				}
				for (int j = 0; j < op[i][1].size(); j++){
					countCoin[(int)(op[i][1][j] - 'A')]--;
					
				}
			}
			if (op[i][2] == "down"){
				for (int j = 0; j < op[i][0].size(); j++){
					countCoin[(int)(op[i][0][j] - 'A')]--;
					//light[(int)(op[i][0][j] - 'A')] = 1;
				}
				for (int j = 0; j < op[i][1].size(); j++){
					countCoin[(int)(op[i][1][j] - 'A')]++;
				}
			}

			if (op[i][2] == "even"){
				for (int j = 0; j < op[i][0].size(); j++){
					allCoin[(int)(op[i][0][j] - 'A')] = true;
				}
				for (int j = 0; j < op[i][1].size(); j++){
					allCoin[(int)(op[i][1][j] - 'A')] = true;
				}
			}
		}

		
		int index = 0;
		int maxCount = 0;
		for (int i = 0;i < 12; i++){
			if (!(allCoin[i] )){
				if (maxCount < abs(countCoin[i])){
					index = i;
					maxCount = abs(countCoin[i]);
				}
			}
		}

		string result = "A";
		char str = (char)('A' + index);
		result[0] = str;
		result += " is the counterfeit coin and it is ";
		if (maxCount == countCoin[index]){
			result += "heavy.";
		}
		else{
			result += "light.";
		}

		cout << result << endl;
	//}

	return 0;
}

