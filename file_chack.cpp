#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;


//×Ö·û´®·Ö¸îº¯Êı
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

bool isKeyBe(map<string, int>mMap, string key){
	return mMap.find(key) != mMap.end();
}

int main(){

	string str;
	map<string, int> result;
	vector<string> file_last8;
	while (getline(cin, str)){

		if (str == ""){
			break;
		}
		vector<string> filename = split(str, "\\");

		vector<string> Onlyfilename = split(filename[filename.size() - 1], " ");


		if (Onlyfilename[0].size() > 16){
			int end = Onlyfilename[0].size() - 16;
			Onlyfilename[0].erase(0, end);
		}

		string useFileName = Onlyfilename[0] + " " + Onlyfilename[1];

		if (count(file_last8.begin(), file_last8.end(), useFileName) == 0){
			//file_last8.erase(find(file_last8.begin(), file_last8.end(), useFileName));
			file_last8.push_back(useFileName);
		}

		/*if (file_last8.size() > 8){
		file_last8.erase(file_last8.begin());
		}*/



		if (!isKeyBe(result, useFileName)){
			result[useFileName] = 1;
		}
		else{
			result[useFileName]++;
		}
	}

	if (file_last8.size() > 8){
		for (int i = file_last8.size() - 8; i < file_last8.size(); i++){
			cout << file_last8[i] << " " << result[file_last8[i]] << endl;
		}
	}
	else{
		for (int i = 0; i < file_last8.size(); i++){
			cout << file_last8[i] << " " << result[file_last8[i]] << endl;
		}
	}



	/*string str, pattern;
	while (cin >> str >> pattern){
	cout << count(str.begin(), str.end(), pattern) << endl;
	}*/


	return 0;

}