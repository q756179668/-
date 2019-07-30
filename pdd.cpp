//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
////字符串分割函数
//vector< string> split(string str, string pattern)
//{
//	vector<string> ret;
//	if (pattern.empty()) return ret;
//	size_t start = 0, index = str.find_first_of(pattern, 0);
//	while (index != str.npos)
//	{
//		if (start != index)
//			ret.push_back(str.substr(start, index - start));
//		start = index + 1;
//		index = str.find_first_of(pattern, start);
//	}
//	if (!str.substr(start).empty())
//		ret.push_back(str.substr(start));
//	return ret;
//}
//
//int main(){
//	string a, b;
//	getline(cin,a);
//	getline(cin, b);
//	vector<string> array_a, array_b;
//	array_a = split(a, " ");
//	array_b = split(b, " ");
//
//	int i = 1;
//	for (; i < array_a.size(); i++){
//		if (array_a[i - 1] > array_a[i]){
//			break;
//		}
//	}
//	bool flg = false;
//	for (int j = 0; j < array_b.size(); j++){
//		if (i <  (array_a.size() - 1) && array_b[j] > array_a[i - 1] && array_b[j] > array_a[i + 1]){
//			array_a[i] = array_b[j];
//			flg = true;
//		}
//		else if (i == (array_a.size() - 1) && array_b[j] > array_a[i - 1]){
//			array_a[i] = array_b[j];
//			flg = true;
//		}
//	}
//	if (flg){
//		for (int k = 0; k < array_a.size(); k++){
//			cout << array_a[k] << " ";
//		}
//	}
//	else{
//		cout << "NO";
//	}
//	return 0;
//}



#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Maxceng = 0;

struct Jimu
{
	int mLi = 0;
	int mWi = 0;
};

bool compare(Jimu a, Jimu b)
{
	return a.mLi<b.mLi; //升序排列，如果改为return a>b，则为降序
}

void putNext(vector<Jimu>mJimu,int index,int nowceng,int mWi,int nowWi){
	if (index == 0){
		if (nowWi + mJimu[index].mWi <= 7 * mWi){
			nowceng++;
		}
		if (nowceng > Maxceng){
			Maxceng = nowceng;
		}
		return;
	}
	for (int i = index - 1; i >= 0;i--){
		
		putNext(mJimu, i, nowceng, mJimu[index-1].mWi, nowWi);
		if (nowWi + mJimu[i].mWi <= 7 * mWi){
			putNext(mJimu, i, nowceng + 1, mJimu[index-1].mWi, nowWi + mJimu[i].mWi);
		}
		
	}
}

int main(){

	int N;
	cin >> N;

	vector<Jimu>mJimu;
	for (int i = 0; i < N; i++){
		Jimu mLi;
		cin >> mLi.mLi;
		mJimu.push_back(mLi);
	}
	for (int i = 0; i < N; i++){
		cin >> mJimu[i].mWi;
	}
	sort(mJimu.begin(), mJimu.end(),compare);

	int nowIndex = 0;
	int NowCeng = 1;
	int NowWi = mJimu[mJimu.size() - 1].mWi;
	putNext(mJimu, mJimu.size(),0,0,0);

	return 0;
}