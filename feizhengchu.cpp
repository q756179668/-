#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int>s(n, 0);//保存余数
	vector<int>temp(k, 0);//记录每个余数的个数，余数可以是0-k-1
	for (int i = 0; i<n; i++)
	{
		int a;
		cin >> a;
		a = a%k;//余数
		s[i] = a;
		temp[a]++;


	}
	int res = 0;
	if (temp[0] != 0)
		res++;
	int i = 1, j = k - 1;//余数1和k-1的只能取一种，取数量多的那种
	while (i<j)
	{
		res = res + max(temp[i], temp[j]);
		i++;
		j--;
	}
	if (i == j&&temp[i] != 0)
		res++;
	cout << res << endl;
}