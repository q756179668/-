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
				if (col == arr[i] || abs(row - i) == abs(col - arr[i])) //��ͬһ�л�����ͬһб�ߡ�һ������ͬһ��
				return false;
			}
			return true;
		}

		void FindNQueen(int k) {
			if (k == n) {   //���һ�ֽ⣬ count+1
				count++;
	/*			vector<int> mArr;
				for (int i = 0; i < n; i++){
					mArr.push_back(arr[i]);
				}
				
				mAllArrList.push_back(mArr);*/
			return;
			}

			for (int i = 0; i < n; i++) {
				if (Check(k, i)) {   //����Ƿ���������
					arr[k] = i;      //��¼
					FindNQueen(k + 1);   //�ݹ����
				}
			}
		}

		//k  ��ǰ�����˶��ٸ�λ�á�   l ��б�߲����ߵ�λ�ã� r ��б�߲����ߵ�λ�á�
		void FindNQueen(int k, int l, int r){
			if (k == upperlim){
				count++;
				return;
				
			}
			int z = upperlim & (~(k | l | r));  //���ߵ�λ�ã� ��nnȡ������ȥ��ǰ������1
			while (z != 0){
				int index = z & (~z + 1);   //���ұߵ�һ��1�� ��Ҫ�Żʺ��λ�á�
				z -= index;   //ȥ�����λ�á�
				FindNQueen(k + index, (l + index) << 1, (r + index) >> 1);   //������һ����
			}
		}

		vector<vector<int>> mAllArrList;
		long count;

		long upperlim = 1;
};
