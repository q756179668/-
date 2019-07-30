#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

int string_to_int(string num_str){
	int num;
	stringstream ss;
	ss.str(num_str);
	ss >> num;
	return num;
}

void TenToTwo(int n, string* str){

	if (n == 0){
		*str = (char)('0');
		return;
	}
	int count = 8;
	do{
		int yu = n % 2;
		*str = (char)('0' + yu) + *str;
		count--;
		n = n / 2;
	} while (n != 0);
	for (int i = 0; i < count; i++){
		*str = (char)('0') + *str;
	}
}

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

int main(){


	int counts[7] = { 0 };
	string str;

	while (getline(cin, str)){
		bool flg = true;

		if (str == ""){
			break;
		}
		vector<string> ip_mask_str = split(str, "~");

		vector<string> ip_str = split(ip_mask_str[0], ".");
		vector<string> mask_str = split(ip_mask_str[1], ".");

		string mask_part_2;
		for (int i = 0; i < mask_str.size(); i++){
			if (!mask_str[i].empty()){
				string mask_part;
				if (i == 3){
					int last_mask = string_to_int(mask_str[i]);
					if (last_mask == 255){
						flg = false;
						break;
					}
				}
				TenToTwo(string_to_int(mask_str[i]), &mask_part);
				mask_part_2 = mask_part_2 + mask_part;
				bool flg_zero = false;
				for (int j = 0; j < mask_part_2.size(); j++){
					if (mask_part_2[j] == '0'){
						for (int k = j + 1; k < mask_part_2.size(); k++){
							if (mask_part_2[k] == '1'){
								flg_zero = true;
								break;
							}
						}
						break;
					}

				}
				if (flg_zero){

					flg = false;
				}
			}
			else{
				flg = false;
				break;
			}
		}
		if (!flg){
			counts[5]++;
			continue;
		}


		if (ip_str.size() != 4){

			counts[5]++;
			continue;

		}


		int ip1 = string_to_int(ip_str[0]);
		if (ip1 >= 1 && ip1 <= 126){
			counts[0]++;
			if (ip1 == 10){
				counts[6]++;
			}
		}
		if (ip1 >= 128 && ip1 <= 191){
			counts[1]++;
			if (ip1 == 172){
				int ip2 = string_to_int(ip_str[1]);
				if (ip2 >= 16 && ip2 <= 31){
					counts[6]++;
				}

			}
		}
		if (ip1 >= 192 && ip1 <= 223){
			counts[2]++;
			if (ip1 == 192){
				int ip2 = string_to_int(ip_str[1]);
				if (ip2 == 168){
					counts[6]++;
				}

			}
		}
		if (ip1 >= 224 && ip1 <= 239){
			counts[3]++;
		}
		if (ip1 >= 240 && ip1 <= 255){
			counts[4]++;
		}



	}

	/*string str, pattern;
	while (cin >> str >> pattern){
	cout << count(str.begin(), str.end(), pattern) << endl;
	}*/

	for (int i = 0; i < 7; i++){
		cout << counts[i] << " ";
	}
	cout << endl;

	return 0;

}