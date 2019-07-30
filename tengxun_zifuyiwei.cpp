#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	while (cin >> s){
		if (s.length() >= 1 && s.length() <= 1000){
			for (int i = 0; i < s.length(); i++)
			if (s[i] >= 'a' && s[i] <= 'z')
				cout << s[i];
			for (int i = 0; i < s.length(); i++)
			if (s[i] <= 'Z' && s[i] >= 'A')
				cout << s[i];
			cout << endl;
		}
	}
	return 0;
}