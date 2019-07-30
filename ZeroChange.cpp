#include<iostream>

using namespace std;
/**
* 交换数组里n和0的位置
* array: 存储[0-n)的数组
* len: 数组长度
* n: 数组里要和0交换的数
*/

int a[6] = { 4,1,0,5,2,3};

void swap_with_zero(int* array, int len, int n){
	int zIndex = -1;
	int nIndex = -1;
	for (int i = 0; i < len; ++i){
		if (array[i] == 0){
			zIndex = i;
		}
		if (array[i] == n){
			nIndex = i;
		}
	}
	int temp = array[zIndex];
	array[zIndex] = array[nIndex];
	array[nIndex] = temp;
}



	void sort(int* array, int len) {
		int count = 0;
		int targ = 0;
		int index = 0;
		int nowIndex = 0;

		int *arrayIndex = (int*)malloc(sizeof(int)*len);

		for (int i = 0; i < len; i++){
			arrayIndex[array[i]] = i;
		}
		for (; count < len;){
			if (array[0] != 0){
				int ZeroIndex = arrayIndex[0];
				//int nChange = array[arrayIndex[ZeroIndex]];
				swap_with_zero(array, len, ZeroIndex);
				arrayIndex[0] = arrayIndex[ZeroIndex];
				arrayIndex[ZeroIndex] = ZeroIndex;
				count++;
			}
			else{
				if (count == array[count]){
					count++;
				}
				else{
					int ZeroIndex = arrayIndex[0];
					arrayIndex[0] = arrayIndex[array[count]];
					arrayIndex[array[count]] = ZeroIndex;
					swap_with_zero(array, len, array[count]);
					
				}
			}
		}

	}
	
	int main(){

		

		sort(a, 6);

		return 0;
	}
