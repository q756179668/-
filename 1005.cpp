#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

using namespace std;

float getR(int i){
	if (i <= 0){
		return 0;
	}
	else{
		float R_1 = getR(i - 1);
		return sqrt(100 / M_PI + R_1*R_1);
	}
}

float getDis(float xy[1][2]){
	return sqrt(xy[0][0] * xy[0][0] + xy[0][1] * xy[0][1]);
}

int la(int a, int b){
	if (a == 0){
		return b;
	}
	else{
		a = a - 1;
		b = b + 1;
		return la(a, b);
	}
}

int mu(int a, int b){
	if (a==0){
		return 0;
	}
	else{
		a = a - 1;
		return la(b, mu(a, b));
	}
}


int main(){

	int c = 300;
	int d = 400;
	cout << mu(c,d);

	/*int N;
	cin >> N;
	vector<int> liveYear;
	for (int i = 0; i < N ; i++){
		float XY[1][2];
		cin >> XY[0][0] >> XY[0][1] ;
		int year = 0;
		float dis = getDis(XY);
		while (dis > getR(year)){
			year++;
		}
		liveYear.push_back(year);
	}
	for (int j = 0; j < liveYear.size(); j ++){
		cout << "Property " << j+1 << ": This property will begin eroding in year " << liveYear[j] << "."<<endl;
	}
	cout << "END OF OUTPUT." << endl;*/
	return 0;
}