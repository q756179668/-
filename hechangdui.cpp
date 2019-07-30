#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void calIncSub(vector<int> quene, vector<int> &Num){
	for (int i = 1; i<quene.size(); i++)
	for (int j = i - 1; j >= 0; j--)
	if (quene[j]<quene[i] && Num[i]<Num[j] + 1)  //找到前面比当前小的，且【能获得的最大子串计数】
		Num[i] = Num[j] + 1;
}

int main(){
	int n;
	int h;

	while (cin >> n){
		vector<int> quene;
		vector<int> incNum(n, 1);  //初始化为n个1
		vector<int> decNum(n, 1);
		vector<int> totalNum;
		for (int i = 0; i<n; i++){
			cin >> h;
			quene.push_back(h);
		}
		calIncSub(quene, incNum);    //找递增子串计数
		reverse(quene.begin(), quene.end()); //翻转，即找反向的子串计数
		calIncSub(quene, decNum);
		reverse(decNum.begin(), decNum.end());   //反向递增即正向递减
		int max = 0;
		for (int i = 0; i<n; i++){
			totalNum.push_back(incNum[i] + decNum[i]);
			if (totalNum[i]>max)
				max = totalNum[i];
		}
		cout << n - max + 1 << endl;
	}
	return 0;
}