#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;


//×Ö·û´®·Ö¸îº¯Êý
vector< string> split(string str, string pattern)
{
	vector<string> ret;
	if (pattern.empty()) return ret;
	size_t start = 0, index = str.find_first_of(pattern, 0);
	while (index != str.npos)
	{
		if (start != index)
			ret.push_back(str.substr(start, index - start));
		start = index + 1;
		index = str.find_first_of(pattern, start);
	}
	if (!str.substr(start).empty())
		ret.push_back(str.substr(start));
	return ret;
}


bool checkStrIsConSubstr(string str,string Substr){
	bool findFlg = false;
	if (str.find(Substr) != string::npos){
		findFlg = true;
	}
	return findFlg;
}

bool checkStrIsConSelfSubstr(string str){
	bool findFlg = false;
	for (int i = 3; i < str.size() / 2; i++){
		for (int start = 0; start + i < str.size(); start++){
			string zic = str.substr(start, i);
			for (int j = start + i + 1; j < str.size() - i; j++){
				if (str[j] == zic[0]){
					bool IsSame = true;
					for (int k = 1; k < i; k++){
						if (str[j + k] != zic[k]){
							IsSame = false;
							break;
						}
					}
					if (IsSame){
						findFlg = true;
						break;
					}
				}
				if (findFlg){
					break;
				}
			}
		}
	}
	return findFlg;
}

bool isKeyBe(map<char, int>mMap, char key){
	return mMap.find(key) != mMap.end();
}



int getCharIndex_abc(char mChar){
	if (mChar >= 'A' && mChar <= 'Z'){
		return (int)(mChar - 'A');
	}
	if (mChar >= 'a' && mChar <= 'z'){
		return (int)(mChar - 'a');
	}
	return -1;
}

string Sort_str_By_abc(string str){
	string str_sort;
	map<int, vector<char>> allChar;
	for (int i = 0; i < str.size(); i++){
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')){
			int index_abc = getCharIndex_abc(str[i]);
			allChar[index_abc].push_back(str[i]);
		}
	}

	for (map<int, vector<char>>::iterator It = allChar.begin(); It != allChar.end();It++){
		for (vector<char>::iterator it = It->second.begin(); it != It->second.end(); it++){
			str_sort += *it;
		}
	}
	return str_sort;
}

int main(){

	string str; 
	
	while (getline(cin,str)){
	
		string str1 = Sort_str_By_abc(str);
		string a = "" + ' ';
		str1.insert(3,a);
		cout << str1 << endl;
	}
		
	

	/*string str, pattern;
	while (cin >> str >> pattern){
		cout << count(str.begin(), str.end(), pattern) << endl;
	}*/


	return 0;

}