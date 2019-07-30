#include<iostream>

#include<set>
#include<string>
#include<math.h>

#include <queue>

#include<vector>
#include<algorithm>

using namespace std;

//int main(){
//
//	int emptyP;
//	while (cin >> emptyP && emptyP!= 0){
//		int result = 0;
//
//		while (emptyP >= 3){
//			int newP = emptyP / 3;
//			result += newP;
//			emptyP = (emptyP % 3) + newP;
//		}
//		if (emptyP == 2){
//			result++;
//		}
//		cout << result << endl;
//	}
//
//	return 0;
//}

//int main(){
//	int N;
//	while (cin >> N){
//		
//		set<int> result;
//		for (int i = 0; i < N; i++){
//			int num;
//			cin >> num;
//			result.insert(num);
//		}
//		//sort(result.begin(), result.end(), greater<int>());
//		
//		for (set<int>::iterator it = result.begin(); it != result.end(); it++){
//			cout << *it << endl;
//			//printf("%d\n", *it);
//		}
//	} 
//	
//	return 0;
//}

//int main(){
//
//	do{
//		string str;
//		cin >> str;
//		
//		int HxSize = str.size() - 2;
//		int result = 0;
//		for (int i = 0; i < HxSize; i++){
//			if (str[str.size() - i - 1] >= '0' && str[str.size() - i - 1] <= '9'){
//				result += (int)(str[str.size() - i - 1] - '0') * pow(16, i);
//			}
//			else if (str[str.size() - i - 1] >= 'a' && str[str.size() - i - 1] <= 'f'){
//				result += (int)(str[str.size() - i - 1] - 'a' + 10) * pow(16, i);
//			}
//			else if (str[str.size() - i - 1] >= 'A' && str[str.size() - i - 1] <= 'F'){
//				result += (int)(str[str.size() - i - 1] - 'A' + 10) * pow(16, i);
//			}
//			
//		}
//		if (str.size() > 2){
//			cout << result << endl;
//		}
//		
//	} while (getchar() != EOF);
//
//	return 0;
//}


//int main(){
//	queue<int> a, b;
//	int n;
//	while (cin >> n){
//		for (int i = 0; i < n; i++){
//			a.push(i);
//		}
//		int time = 0;
//		while (!a.empty() || !b.empty()){
//			while (!a.empty()){
//				if (b.empty() && a.size() == 1){
//					int last = a.front();
//					a.pop();
//					cout << last << endl;
//					break;
//				}
//				if (time != 2){
//					b.push(a.front());
//					a.pop();
//				}
//				else{
//					a.pop();
//					time = -1;
//				}
//				time++;
//			}
//			while (!b.empty()){
//				if (a.empty() && b.size() == 1){
//					int last = b.front();
//					b.pop();
//					cout << last << endl;
//					break;
//				}
//				if (time != 2){
//					a.push(b.front());
//					b.pop();
//				}
//				else{
//					b.pop();
//					time = -1;
//				}
//				time++;
//			}
//		}
//	}
//	return 0;
//}

//int main(){
//
//	string str;
//	while (cin >> str){
//		vector<char>result;
//		for (int i = 0; i < str.size(); i++){
//			if (find(result.begin(), result.end(), str[i]) == result.end()){
//				result.push_back(str[i]);
//			}
//		}
//		for (vector<char>::iterator it = result.begin(); it != result.end(); it++){
//			cout << *it;
//		}
//		cout << endl;
//		result.clear();
//	}
//
//	return 0;
//}



#include <iostream>
#include <algorithm>
using namespace std;
int map[9][9];
int ansmap[9][9];
bool OutPut_flg = false;
bool isPlace(int count){
	int row = count / 9;
	int col = count % 9;
	int j;
	//同一行
	for (j = 0; j < 9; ++j){
		if (map[row][j] == map[row][col] && j != col){
			return false;
		}
	}
	//同一列
	for (j = 0; j < 9; ++j){
		if (map[j][col] == map[row][col] && j != row){
			return false;
		}
	}
	//同一小格
	int tempRow = row / 3 * 3;
	int tempCol = col / 3 * 3;
	for (j = tempRow; j < tempRow + 3; ++j){
		for (int k = tempCol; k < tempCol + 3; ++k){
			if (map[j][k] == map[row][col] && j != row && k != col){
				return false;
			}
		}
	}
	return true;
}
void backtrace(int count){
	if (count == 81){
		//以下是把所有可行的情况输出
		/*for (int i = 0; i < 9; ++i){
			for (int j = 0; j < 9; ++j){
				ansmap[i][j] =  map[i][j] ;
			}
		}*/
		if (!OutPut_flg){
			OutPut_flg = true;
			for (int i = 0; i < 9; ++i){
				for (int j = 0; j < 9; ++j){
					cout << map[i][j] << " ";
				}
				cout << endl;
			}
		}
		
		return;
	}
	int row = count / 9;
	int col = count % 9;
	if (map[row][col] == 0){
		for (int i = 1; i <= 9; ++i){
			map[row][col] = i;//赋值
			if (isPlace(count)){//可以放
				backtrace(count + 1);//进入下一层
			}
		}
		map[row][col] = 0;//回溯
	}
	else{
		backtrace(count + 1);
	}
}
int main()
{
	do{
		for (int i = 0; i < 9; ++i){
			for (int j = 0; j < 9; ++j){
				cin >> map[i][j];
			}
		}
		backtrace(0);

		for (int i = 0; i < 9; ++i){
			for (int j = 0; j < 9; ++j){
				cout << ansmap[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

	} while (getchar() != EOF);

	return 0;
}