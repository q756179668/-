#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template <typename T>
T getVectorMaxElement(vector<T> mVec){
	auto  max_Element = max_element(mVec.begin(), mVec.end());
	retutn *max_Element;
}

int main(){
	
	
	//去重操作,先排序，再去重
	vector<int> nums;
	for (int i = 0; i < 10; i++){
		int a;
		cin >> a;
		nums.push_back(a);
	}
	sort(nums.begin(), nums.end());
	auto iter = unique(nums.begin(), nums.end());
	nums.erase(iter, nums.end());
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
		cout << *it << " ";
	}

	//去重,不排序
	vector<int> nums1;
	for (int i = 0; i < 10; i++){
		int a;
		cin >> a;
		if (count(nums1.begin(),nums1.end(),a) == 0){
			nums1.push_back(a);
		}
	}
	for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++){
		cout << *it << " ";
	}
	//反向输出
	for (vector<int>::reverse_iterator it = nums1.rbegin(); it != nums1.rend(); it++){
		cout << *it << " ";
	}

	return 0;

}