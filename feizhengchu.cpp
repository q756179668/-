#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int>s(n, 0);//��������
	vector<int>temp(k, 0);//��¼ÿ�������ĸ���������������0-k-1
	for (int i = 0; i<n; i++)
	{
		int a;
		cin >> a;
		a = a%k;//����
		s[i] = a;
		temp[a]++;


	}
	int res = 0;
	if (temp[0] != 0)
		res++;
	int i = 1, j = k - 1;//����1��k-1��ֻ��ȡһ�֣�ȡ�����������
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