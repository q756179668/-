#include<math.h>
#include<vector>

using namespace std;

class NQueen {
private: int n;
		 
		 int* arr;
		 
	//    private int nn;

public: NQueen(int n){
			this->n = n;
			count = 0;
			arr = new int[n];
		};
		~NQueen(){
			mAllArrList.clear();
		};
		bool Check(int row, int col){
			for (int i = 0; i < row; i++){
				if (col == arr[i] || abs(row - i) == abs(col - arr[i])) //在同一列或者在同一斜线。一定不在同一行
				return false;
			}
			return true;
		}

		void FindNQueen(int k) {
			if (k == n) {   //求出一种解， count+1
				count++;
	/*			vector<int> mArr;
				for (int i = 0; i < n; i++){
					mArr.push_back(arr[i]);
				}
				
				mAllArrList.push_back(mArr);*/
			return;
			}

			for (int i = 0; i < n; i++) {
				if (Check(k, i)) {   //检查是否满足条件
					arr[k] = i;      //记录
					FindNQueen(k + 1);   //递归查找
				}
			}
		}

		//k  当前已走了多少个位置。   l 左斜线不能走的位置， r 右斜线不能走的位置。
		void FindNQueen(int k, int l, int r){
			if (k == upperlim){
				count++;
				return;
				
			}
			int z = upperlim & (~(k | l | r));  //能走的位置， 和nn取并可以去掉前面多余的1
			while (z != 0){
				int index = z & (~z + 1);   //最右边的一个1， 即要放皇后的位置。
				z -= index;   //去掉这个位置。
				FindNQueen(k + index, (l + index) << 1, (r + index) >> 1);   //查找下一个。
			}
		}

		vector<vector<int>> mAllArrList;
		long count;

		long upperlim = 1;
};
