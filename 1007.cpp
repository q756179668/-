#include<iostream>
#include<list>
#include <functional>
#include <iostream>
#include <algorithm>

using namespace std;

struct mDNA{
	char* mDNA_charArray;
	int measure;

	mDNA()
	{
		memset(this, 0, sizeof(mDNA));
		//或者是下面的格式 
		//memset(&nNum,0,sizeof(Stu));
	}

};

template<> struct std::greater<mDNA*>{
	bool operator()(mDNA* X, mDNA* Y) const // 重载运算符
	{
		if (X->measure > Y->measure){
			return true;
		}
		else{
			return false;
		}
	}
};


int main(){

	int n,m;
	cin >> n >> m;
	list<mDNA*> result;
	

	for (int j = 0; j < m;j++){
		char *DNA = new char[n];
		
		for (int i = 0; i < n; i++){
			cin >> DNA[i];
		}
		DNA[n] = '\0';
		int count = 0;
		for (int k = 0; k < n;k++){
			for (int l = k; l < n; l++){
				if (DNA[k] > DNA[l]){
					count++;
				}
			}
		}
		mDNA* one_DNA = new mDNA();
		one_DNA->mDNA_charArray = DNA ;
		one_DNA->measure = count;


		result.push_back(one_DNA);

	}
	result.sort(greater<mDNA*>());



	for (list<mDNA*>::reverse_iterator iter = result.rbegin(); iter != result.rend(); iter++){
		cout << (*iter)->mDNA_charArray << endl;
	}

	result.clear();
	return 0;
}