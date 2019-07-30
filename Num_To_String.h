#include<sstream>
#include<string>

using namespace std;

class CNum_Interchange_String{
public :
	template <typename T>
	static string num_to_string(T num){
		stringstream ss;
		ss << num;
		return ss.str();
	}

	
	static int string_to_int(string num_str){
		int num;
		stringstream ss;
		ss.str(num_str);
		ss >> num;
		return num;
	}

	static float string_to_float(string num_str){
		float num;
		stringstream ss;
		ss.str(num_str);
		ss >> num;
		return num;
	}

	static double string_to_double(string num_str){
		double num;
		stringstream ss;
		ss.str(num_str);
		ss >> num;
		return num;
	}

	static long string_to_long(string num_str){
		long num;
		stringstream ss;
		ss.str(num_str);
		ss >> num;
		return num;
	}
	
	void TenToTwo(int n ,string str){
		char buff[64];
		itoa(n, buff, 2);
		str.append(buff);
	}

};

