#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	string str;
	while (cin >> str){
		int num_count[10] = { 0 };
		int Nine_count[10] = { 0 };
		vector<char> allSTR;
		for (int i = 0; i <str.size(); i++){
			allSTR.push_back(str[i]);
			switch (str[i]){
			case 'z':
			case 'Z':
				Nine_count[0]++;
			case 'w':
			case 'W':
				Nine_count[1]++;
				break;
			case 'u':
			case 'U':
				Nine_count[2]++;
				break;
			case 'x':
			case 'X':
				Nine_count[3]++;
				break;
			case 'g':
			case 'G':
				Nine_count[4]++;
				break;
			case 'o':
			case 'O':
				Nine_count[5]++;
				break;
			case 'h':
			case 'H':
				Nine_count[6]++;
				break;
			case 'f':
			case 'F':
				Nine_count[7]++;
				break;
			case 's':
			case 'S':
				Nine_count[8]++;
				break;
			case 'n':
			case 'N':
				Nine_count[9]++;
				break;
			default:
				break;
			}
		}
		num_count[0] = Nine_count[0];
		num_count[1] = Nine_count[5] - Nine_count[1] - Nine_count[2];
		num_count[2] = Nine_count[1];
		num_count[3] = Nine_count[6] - Nine_count[4];
		num_count[4] = Nine_count[2];
		num_count[5] = Nine_count[7] - Nine_count[2];
		num_count[6] = Nine_count[3];
		num_count[7] = Nine_count[8] - Nine_count[3];
		num_count[8] = Nine_count[4];
		num_count[9] = (Nine_count[9] - num_count[1] - num_count[7])/2;

		for (int i = 0; i < 10; i++){
			for (int j = 0; j < num_count[i]; j++){
				cout << (i);
			}
		}
		cout << endl;
	}
}