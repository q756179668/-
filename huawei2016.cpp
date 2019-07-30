#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

map<int, int> mscore;
vector<int> result;

void getMax( int l, int r){
	int max = mscore[l];
	for (int i = l; i <= r; i++){
		if (max < mscore[i]){
			max = mscore[i];
		}
	}
	result.push_back(max);
}

void changeS(int id, int newScore){
	mscore[id] = newScore;
}

int main(){
	int N, M;

	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		int score;
		cin >> score;
		mscore[i] = score;
	}

	string op; int data1, data2;
	for (int i = 0; i< M; i++){
		cin >> op >> data1>>data2;
		if (op[0] == 'Q'){
			getMax(data1, data2);
			continue;
		}
		if (op[0] == 'U'){
			changeS( data1, data2);
			continue;
		}
	}
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
	return 0;
}