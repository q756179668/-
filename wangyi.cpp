#include<iostream>
#include <vector>

using namespace std;

vector<int> allSumWight;
vector<int> result;
int num[6] = { 5, 4, 3, 2, 1, 0 };
int num1[6][6] = { { 6, 2, 4, 1, 3, 6 },
				   { 3, 6, 0, 5, 6, 2 }, 
				   { 1, 5, 6, 6, 0, 4 }, 
				   { 4, 0, 6, 6, 5, 1 }, 
				   { 2, 6, 5, 0, 6, 3 }, 
				   { 6, 3, 1, 4, 2, 6 } };


void walk(char ** marr, int mnx, int mny, int mtx, int mty, int mwight[], int faceNum, int RNum, int sum,int** mused,int mM,int mN){
	if (mnx == mtx && mny == mty){
		allSumWight.push_back(sum + mwight[num1[faceNum][RNum]]);
		return;
	}
	int** used;
	used = (int **)malloc(mM * sizeof(int *));
	for (int i = 0; i < mM; i++){
		
		used[i] = (int *)malloc(mN * sizeof(int));
		for (int j = 0; j < mN; j++){
			used[i][j] = mused[i][j];
		}
	}
	if (used[mnx][mny] != 1){
		used[mnx][mny] = 1;
	}
	else{
		return;
	}
	if (mnx >= mM || mnx < 0 || mny >= mN || mny < 0){
		return;

	}

	if (mnx == mM - 1 || mnx == 0){
		if (marr[mnx - 1][mny] != '#'){
			sum += mwight[num1[faceNum][RNum]];
			walk(marr, mnx - 1, mny, mtx, mty, mwight, num1[faceNum][RNum], RNum, sum, used, mM, mN);
		}
		if (marr[mnx][mny - 1] != '#'){
			sum += mwight[num1[faceNum][RNum]];
			walk(marr, mnx, mny - 1, mtx, mty, mwight, faceNum, num1[faceNum][RNum], sum, used, mM, mN);
		}
		return;
	}
	if (mny == mN - 1 || mny == 0){
		if (marr[mnx - 1][mny] != '#'){
			sum += mwight[num1[faceNum][RNum]];
			walk(marr, mnx - 1, mny, mtx, mty, mwight, num1[faceNum][RNum], RNum, sum, used, mM, mN);
		}
		if (marr[mnx][mny - 1] != '#'){
			sum += mwight[num1[faceNum][RNum]];
			walk(marr, mnx, mny - 1, mtx, mty, mwight, faceNum, num1[faceNum][RNum], sum, used, mM, mN);
		}
		return;
	}
	if (marr[mnx + 1][mny] != '#'){
		sum += mwight[num1[faceNum][RNum]];
		walk(marr, mnx + 1, mny, mtx, mty, mwight, num[num1[faceNum][RNum]], RNum, sum, used, mM, mN);
	}
	if (marr[mnx][mny + 1] != '#'){
		sum += mwight[num1[faceNum][RNum]];
		walk(marr, mnx, mny + 1, mtx, mty, mwight, faceNum, num[num1[faceNum][RNum]], sum, used, mM, mN);
	}
	if (marr[mnx - 1][mny] != '#'){
		sum += mwight[num1[faceNum][RNum]];
		walk(marr, mnx - 1, mny, mtx, mty, mwight, num1[faceNum][RNum], RNum, sum, used, mM, mN);
	}
	if (marr[mnx][mny - 1] != '#'){
		sum += mwight[num1[faceNum][RNum]];
		walk(marr, mnx, mny - 1, mtx, mty, mwight, faceNum, num1[faceNum][RNum], sum, used, mM, mN);
	}

	/*if (mnx < mtx && mny < mty){
		if (marr[mnx + 1][mny] != '#'){
			sum += mwight[num1[faceNum][RNum]];
			walk(marr, mnx + 1, mny, mtx, mty, mwight, num[num1[faceNum][RNum]], RNum, sum, used, mM, mN);
		}
		if (marr[mnx][mny + 1] != '#'){
			sum += mwight[num1[faceNum][RNum]];
			walk(marr, mnx, mny + 1, mtx, mty, mwight, faceNum, num[num1[faceNum][RNum]], sum, used, mM, mN);
		}
	}
	if (mnx > mtx && mny > mty){
		if (marr[mnx - 1][mny] != '#'){
			sum += mwight[num1[faceNum][RNum]];
			walk(marr, mnx - 1, mny, mtx, mty, mwight, num1[faceNum][RNum], RNum, sum, used, mM, mN);
		}
		if (marr[mnx][mny - 1] != '#'){
			sum += mwight[num1[faceNum][RNum]];
			walk(marr, mnx, mny - 1, mtx, mty, mwight, faceNum, num1[faceNum][RNum], sum, used, mM, mN);
		}
	}
	if (mnx == mtx && mny != mty){
		if (mny > mty){
			if (marr[mnx][mny - 1] != '#'){
				sum += mwight[num1[faceNum][RNum]];
				walk(marr, mnx, mny - 1, mtx, mty, mwight, faceNum, num1[faceNum][RNum], sum, used, mM, mN);
			}
		}
		if (mny < mty){
			if (marr[mnx][mny + 1] != '#'){
				sum += mwight[num1[faceNum][RNum]];
				walk(marr, mnx, mny + 1, mtx, mty, mwight, faceNum, num[num1[faceNum][RNum]], sum, used, mM, mN);
			}
		}
	}
	if (mnx != mtx && mny == mty){
		if (mnx > mtx){
			if (marr[mnx - 1][mny] != '#'){
				sum += mwight[num1[faceNum][RNum]];
				walk(marr, mnx - 1, mny, mtx, mty, mwight, num1[faceNum][RNum], RNum, sum, used, mM, mN);
			}
		}
		if (mnx < mtx){
			if (marr[mnx + 1][mny] != '#'){
				sum += mwight[num1[faceNum][RNum]];
				walk(marr, mnx + 1, mny, mtx, mty, mwight, num[num1[faceNum][RNum]], RNum, sum, used, mM, mN);
			}
		}
	}*/
}

int main(){
	int T;
	cin >> T;
	for (int time = 0;time < T; time++){
		int M, N;
		cin >> M >> N;
		char** arr;
		int** used;
		arr = (char **)malloc(M * sizeof(char *));
		used = (int **)malloc(M * sizeof(int *));
		for (int i = 0; i < M; i++){
			arr[i] = (char *)malloc(N * sizeof(char));
			used[i] = (int *)malloc(N * sizeof(int));
			for (int j = 0; j < N; j++){
				cin >> arr[i][j];
				used[i][j] = 0;
			}
		}
		int sx, sy, tx, ty;
		cin >> sx >> sy >> tx >> ty;
		int wight[6];
		for (int i = 0; i < 6; i++){
			cin >> wight[i];
		}
		int Mainsum = 0;
		walk(arr, sx, sy, tx, ty, wight, 0, 2, Mainsum, used,M,N);
		int minResult = 9999999;
		if (allSumWight.size() == 0){
			result.push_back(-1);
			break;
		}
		for (int k = 0; k < allSumWight.size(); k++){
			if (minResult > allSumWight[k]){
				minResult = allSumWight[k];
			}
		}
		result.push_back(minResult);
		allSumWight.clear();
	}

	for (int k = 0; k < result.size(); k++){
		cout << result[k] << endl;
	}
	return 0;

}

