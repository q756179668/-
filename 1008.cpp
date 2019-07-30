#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>

using namespace std;


int main(){

	int Haab_Max_Days = 365;
	int Haab_Max_Months = 19;
	int Haab_Max_Date_20 = 20;
	int Haab_Max_Date_5 = 5;

	int Tzolkin_Max_Days = 260;
	int Tzolkin_NameOfTheDay = 20;
	int Tzolkin_Number = 13;


	string Haab_month[] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
	string Tzolkin_month[] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
	
	map<string,int> mHaabMap;
	for (int i = 0; i < sizeof(Haab_month) / sizeof(Haab_month[0]) ; i++){
		mHaabMap[Haab_month[i]] = i;
	}

	map<int, string> mTzolkinMap;
	for (int i = 0; i < sizeof(Tzolkin_month) / sizeof(Tzolkin_month[0]); i++){
		mTzolkinMap[i] = Tzolkin_month[i];
	}

	int n;
	cin >> n;
	//cout << n;

	vector<string> result;

	while (n--){
		string Haab_date, Haab_month, Haab_year;
		cin >> Haab_date >> Haab_month >> Haab_year;
		Haab_date.erase(Haab_date.end() - 1, Haab_date.end());
		int Haab_year_int = atoi(Haab_year.c_str());
		int Haab_month_int = mHaabMap[Haab_month];
		int Haab_date_int = atoi(Haab_date.c_str());

		int allDays = Haab_year_int * Haab_Max_Days + Haab_month_int * Haab_Max_Date_20 + Haab_date_int;

		int Tzolkin_year_int = allDays / Tzolkin_Max_Days;
		int Tzolkin_NameOfTheDay_int = (allDays % Tzolkin_Max_Days) % Tzolkin_NameOfTheDay;
		int Tzolkin_Number_big = (allDays % Tzolkin_Max_Days) % Tzolkin_Number ;
		/*while (Tzolkin_Number_big > 13){
			Tzolkin_Number_big = Tzolkin_Number_big % Tzolkin_Number;
		}*/
		int Tzolkin_Number_int = Tzolkin_Number_big + 1;

		stringstream ss;
		ss << Tzolkin_Number_int;
		string Tzolkin_Number_str = ss.str();

		stringstream ss1;
		ss1 << Tzolkin_year_int;
		
		string Tzolkin_year_str = ss1.str();

		string result_one = Tzolkin_Number_str + " " + mTzolkinMap[Tzolkin_NameOfTheDay_int] + " " + Tzolkin_year_str;
		result.push_back(result_one);
	}
	cout << result.size() << endl;
	for (vector<string>::iterator it = result.begin();it != result.end(); it++){
		cout << *it << endl;
	}

	return 0;
}