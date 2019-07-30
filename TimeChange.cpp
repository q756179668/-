#include<iostream>
#include<string>

using namespace std;

int main(){

	string time12;
	do{
		cin >> time12;
		if (time12[time12.size() - 2] == 'P'){
			int hour = (int)((time12[0] - '0') * 10) + (int)((time12[1] - '0'));
			hour += 12;
			if (hour == 24){
				hour = 12;
			}
			int hour1 = hour / 10;
			int hour2 = hour % 10;
			time12[0] = '0' + hour1;
			time12[1] = '0' + hour2;
			time12[time12.size() - 2] = '\0';
			time12[time12.size() - 1] = '\0';
			cout << time12;
		}
		else{
			int hour = (int)((time12[0] - '0') * 10) + (int)((time12[1] - '0'));
			hour += 12;
			if (hour == 24){
				hour = 0;
			}
			int hour1 = hour / 10;
			int hour2 = hour % 10;
			time12[0] = '0' + hour1;
			time12[1] = '0' + hour2;
			time12[time12.size() - 2] = '\0';
			time12[time12.size() - 1] = '\0';
			cout << time12;
		}
	} while (getchar() != EOF);

	return 0;
}