#include<iostream>
#include<map>
#include<string>

using namespace std;



bool isKeyBe(map<int, int>mMap,int key){
	return mMap.find(key) != mMap.end();
}

//∞¥key¥Û–°≈≈–Ú
typedef pair<int, int> PAIR;
ostream& operator<<(ostream& out, const PAIR& p) {
	return out << p.first << "\t" << p.second;
}

int main(){
	/*int N;
	while (getline(cin , N)){
		map<int, int>result;
		for (int i = 0; i < N; i++){
			int index, value;
			cin >> index >> value;

			if (!isKeyBe(result, index)){
				result[index] = value;
			}
			else{
				result[index] += value;
			}
		}
		for (map<int, int>::iterator it = result.begin(); it != result.end(); it++){
			cout << it->first << " " << it->second << endl;
		}
	}*/

	string str;
	while (getline(cin, str)){
		map<int, int>result;
	}

}