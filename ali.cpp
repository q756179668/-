#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

//
//int __partition(int arr[], int l, int r){
//
//	int v = arr[l];
//
//	int j = l; // arr[l+1...j] < v ; arr[j+1...i) > v
//	for (int i = l + 1; i <= r; i++)
//	if (arr[i] < v){
//		j++;
//		swap(arr[j], arr[i]);
//	}
//
//	swap(arr[l], arr[j]);
//
//	return j;
//}
//
//// 对arr[l...r]部分进行快速排序
//void __quickSort(int arr[], int l, int r){
//
//	if (l >= r)
//		return;
//
//	int p = __partition(arr, l, r);
//	__quickSort(arr, l, p - 1);
//	__quickSort(arr, p + 1, r);
//}
//
//
//void quickSort(int* arr, int n){
//
//	__quickSort(arr, 0, n - 1);
//}




//
//int main(){
//	int L,R;
//	cin >> L >> R;
//	int count = 0;
//	for (int i = L; i <= R; i++){
//		int counti = 0;
//		int mi = i;
//		while (counti < 2 && mi != 0){
//			if (mi % 2 == 0){
//				counti ++ ;
//			}
//			mi = mi / 2;
//		}
//		if (counti == 1){
//			count++;
//		}
//	}
//
//	cout << count << endl;
//	return 0;
//}


//
//bool findPath(char ** mzim, int **mused, int mn, int mm,int mn1, int mm1, int N, int M){
//
//	
//
//	if (mn1 >= N || mm1 >= M || mn1 < 0|| mm1 < 0){
//		return false;
//	}
//	else{
//
//		if (mzim[mn][mm] == mzim[mn1][mm1]){
//			if (mused[mn][mm] == 1){
//				return true;
//			}
//			else{
//				mused[mn][mm] = 1;
//				return findPath(mzim, mused, mn1, mm1, mn1, mm1 + 1, N, M) || findPath(mzim, mused, mn1, mm1, mn1, mm1 - 1, N, M)
//					|| findPath(mzim, mused, mn1, mm1, mn1 + 1, mm1, N, M) || findPath(mzim, mused, mn1, mm1, mn1 - 1, mm1, N, M);
//			}
//		}
//		else{
//			return false;
//		}
//
//		
//	}
//}
//
//int main(){
//	int n, m;
//	cin >> n >> m;
//	char ** zim = new char*[m];
//	int ** used = new int*[m];
//	memset(used, 0, sizeof(used));
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < m; j++){
//			cin >> zim[i][j];
//		}
//	}
//	bool flg = false;
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < m; j++){
//			if (findPath(zim, used, i, j, i, j + 1, n, m) || findPath(zim, used, i, j, i, j - 1, n, m)
//				|| findPath(zim, used, i, j, i - 1, j, n, m) || findPath(zim, used, i, j, i - 1, j, n, m)){
//				flg = true;
//				break;
//			}
//		}
//	}
//	if (flg){
//		cout << "Yes" << endl;
//	}
//	else{
//		cout << "No" << endl;
//	}
//
//	return 0;
//}
#include <map>

int __partition(double arr[], int l, int r){

	int v = arr[l];

	int j = l; 
	for (int i = l + 1; i <= r; i++)
	if (arr[i] < v){
		j++;
		swap(arr[j], arr[i]);
	}

	swap(arr[l], arr[j]);

	return j;
}

void __quickSort(double arr[], int l, int r){

	if (l >= r)
		return;

	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}


void quickSort(double* arr, int n){

	__quickSort(arr, 0, n - 1);
}

int main(){

	int n, w;
	cin >> n >> w;

	int* wi = new int[n];
	int* vi = new int[n];
	double* mwv = new double[n];
	for (int i = 0; i < n; i++){
		cin >> wi[i] >> vi[i];
	}

	map<double, int> Allqz;
	for (int i = 0; i < n; i++){
		mwv[i] = vi[i] / wi[i];
		Allqz[vi[i] / wi[i]] = i;
	}
	quickSort(mwv,n);
	int result = 0;
	int result2 = 0;
	for (int i = 0; i < n; i++){
		if (w > wi[Allqz[mwv[i]]]){
			w = w - wi[i];
			result += vi[Allqz[mwv[i]]];
		}
	}
	for (int i = 1; i < n; i++){
		if (w > wi[Allqz[mwv[i]]]){
			w = w - wi[i];
			result2 += vi[Allqz[mwv[i]]];
		}
	}

	cout << max(result,result2);
	return 0;
}