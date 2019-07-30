#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int N;
	while (cin >> N){
		vector<int> allNum;
		for (int i = 0; i < N; i++){
			int num;
			cin >> num;
			allNum.push_back(num);
		}
		if (N == 1)
		{
			cout << 0 << " " << 0 << endl;
			continue;
		}
		sort(allNum.begin(), allNum.end());
		if (allNum[0] == allNum[N - 1])
		{
			int num = N*(N - 1) / 2;
			cout << num << " " << num << endl;
			continue;
		}
		int maxNum = count(allNum.begin(), allNum.end(), allNum[N - 1]);
		int minNum = count(allNum.begin(), allNum.end(), allNum[0]);
		int max = maxNum*minNum;
		int minValue = allNum[1] - allNum[0];
		for (int i = 1; i<N; i++)
		if (allNum[i] - allNum[i - 1]<minValue)
			minValue = allNum[i] - allNum[i - 1];
		int min = 0;
		for (int i = 1; i<N; i++)
		for (int j = i - 1; j >= 0; j--)
		if (allNum[i] - allNum[j] == minValue)
			min++;
		else
			break;
		cout << min << " " << max << endl;
	}
	return 0;
}