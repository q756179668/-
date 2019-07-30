#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map> 

using namespace std;

int main(){
	int Num;
	cin >> Num;
	map<string, int> mHashMap;
	while (Num--){
		string everyNums;
		cin >> everyNums;
		string everyNums_del(10000, ' ');
		int index = 0;
		for (int i = 0; i < everyNums.size() ; i++){
			if (index == 3){
				everyNums_del[index++] = '-';
				//i--;
			}
			switch (everyNums[i])
			{
			case '0':
				everyNums_del[index++] = '0';
				break;
			case '1':
				everyNums_del[index++] = '1';
				break;
			case 'A':
			case 'B':
			case 'C':
			case '2':
				everyNums_del[index++] = '2';
				break;
			case 'D':
			case 'E':
			case 'F':
			case '3':
				everyNums_del[index++] = '3';
				break;
			case 'G':
			case 'H':
			case 'I':
			case '4':
				everyNums_del[index++] = '4';
				break;
			case 'J':
			case 'K':
			case 'L':
			case '5':
				everyNums_del[index++] = '5';
				break;
			case 'M':
			case 'N':
			case 'O':
			case '6':
				everyNums_del[index++] = '6';
				break;
			case 'P':
			case 'R':
			case 'S':
			case '7':
				everyNums_del[index++] = '7';
				break;
			case 'T':
			case 'U':
			case 'V':
			case '8':
				everyNums_del[index++] = '8';
				break;
			case 'W':
			case 'X':
			case 'Y':
			case '9':
				everyNums_del[index++] = '9';
				break;
			default:
				break;
			}
		}
		everyNums_del.erase(everyNums_del.begin() + 8, everyNums_del.end());
		if (mHashMap.find(everyNums_del) == mHashMap.end()){
			mHashMap[everyNums_del] = 1;
		}
		else{
			mHashMap[everyNums_del]++;
		}
	}
	vector<string> Result_Str;
	for (map<string, int>::iterator mit = mHashMap.begin(); mit != mHashMap.end(); mit++){
		if (mit->second != 1){
			Result_Str.push_back(mit->first + ' ' + (char)(mit->second + (int)'0'));
		}
	}

	if (Result_Str.size() == 0){
		cout << "No duplicates." << endl;
		return 0;
	}

	sort(Result_Str.begin(), Result_Str.end());
	for (vector<string>::iterator it = Result_Str.begin(); it != Result_Str.end(); it++){
		cout << *it << endl;
	}

	Result_Str.clear();
	mHashMap.clear();
	return 0;
}