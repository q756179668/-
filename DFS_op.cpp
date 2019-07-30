#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> mallVpq,int mindex, int mN,int mmax,int* mMax,int mM){
	if (mindex >= mM || mN - mallVpq[mindex][0]  < 0 ){
		if (mmax > *mMax){
			*mMax = mmax;
			return;
		}
	}
	for (int i = mindex; i < mM; i++){
		int nowN;
		int nowmax;
		if (mallVpq[i][2] == 0){
			if (mallVpq[i][3] != 1){
				nowN = mN - mallVpq[i][0];
				nowmax = mmax + mallVpq[i][0] * mallVpq[i][1];
				mallVpq[i][3] = 1;
				dfs(mallVpq, mindex + 1, nowN, nowmax, mMax, mM);
				mallVpq[i][3] = 0;
			}
			else{
				nowN = mN;
				nowmax = mmax;
				dfs(mallVpq, mindex + 1, nowN, nowmax, mMax, mM);
			}
			
		}
		else{
			if (mallVpq[mallVpq[i][2]-1][3]){
				if (mallVpq[i][3] != 1){
					nowN = mN - mallVpq[i][0];
					nowmax = mmax + mallVpq[i][0] * mallVpq[i][1];
					mallVpq[i][3] = 1;
					dfs(mallVpq, mindex + 1, nowN, nowmax, mMax, mM);
					mallVpq[i][3] = 0;
				}
				else{
					nowN = mN;
					nowmax = mmax;
					dfs(mallVpq, mindex + 1, nowN, nowmax, mMax, mM);
				}
				
			}
			else{
				nowN = mN;
				nowmax = mmax;
				dfs(mallVpq, mindex + 1, nowN, nowmax, mMax, mM);
			}
		}
	}
}

int main(){
	int N, m;
	while (cin >> N >> m){
		
		vector<vector<int>> allVpq;
		for (int i = 0; i < m;i++){
			int a[4];
			cin >> a[0] >> a[1] >> a[2];
			a[3] = 0;
			vector<int> b;
			b.push_back(a[0]);
			b.push_back(a[1]);
			b.push_back(a[2]);
			b.push_back(a[3]);
			allVpq.push_back(b);
		}
		int Max = 0;
		for (int i = 0; i < m; i++){
			int max = 0;
			int mN = N;
			for (int j = i; j < m; j++){
				if (mN - allVpq[j][0] >= 0){
					if (allVpq[j][2] == 0){
						mN -= allVpq[j][0];
					}
				}
			}
		}
		cout << Max;
	}
}