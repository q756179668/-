#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<sstream>

using namespace std;

bool isKeyBe(map<int, int>mMap, int key){
	return mMap.find(key) != mMap.end();
}

//∞¥key¥Û–°≈≈–Ú
typedef pair<int, int> PAIR;
ostream& operator<<(ostream& out, const PAIR& p) {
	return out << p.first << "\t" << p.second;
}

template <typename T>
static string num_to_string(T num){
	stringstream ss;
	ss << num;
	return ss.str();
}

int main(){

	int sizeOfI;
	while (cin >> sizeOfI){
		vector<string>I;
		set<int>R;
		map<int, int> counts;
		vector<vector<int>> AllIndex;

		
		for (int i = 0; i < sizeOfI; i++){
			string numOfi;
			cin >> numOfi;
			I.push_back(numOfi);
		}
		int sizeOfR;
		cin >> sizeOfR;
		for (int i = 0; i < sizeOfR; i++){
			int numOfR;
			cin >> numOfR;
			R.insert(numOfR);
		}

		int count = 0;
		for (set<int>::iterator Rit = R.begin();Rit != R.end();Rit++){
			vector<int> index;
			for (int j = 0; j < I.size(); j++){
				string str = num_to_string(*Rit);
				if (I[j].find(str) != string::npos){
					if (isKeyBe(counts,  *Rit)){
						counts[*Rit]++;
					}
					else{
						counts[*Rit] = 1;
					}
					index.push_back(j);
					count++;
				}
			}
			AllIndex.push_back(index);
		}
		int allSize = 2 * counts.size() + count * 2;
		if (allSize != 0){
			cout << allSize << " ";
		}

		int mIndex = 0;
		for (map<int, int>::iterator it = counts.begin(); it != counts.end(); it++){
			
			while (AllIndex[mIndex].size() == 0){
				mIndex++;
			}
				cout << it->first << " " << it->second << " ";
				for (vector<int>::iterator indexIt = AllIndex[mIndex].begin(); indexIt != AllIndex[mIndex].end(); indexIt++){
					cout << *indexIt << " " << I[*indexIt]<<" ";
				}
				mIndex++;
			
		}
		cout << endl;;
	} 
	



	return 0;
}