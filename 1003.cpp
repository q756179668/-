#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
	double sample;
	double Max_Sample = 0;
	vector<double> AllSample;
	map<double,double> AllSample_R;
	map<double, int> mMap;

	while (true){
		cin >> sample;
		if (sample != 0.00000000000000000){
			AllSample.push_back(sample);
			if (sample > Max_Sample){
				Max_Sample = sample;
			}
		}
		else{
			break;
		}
	}
	double l = 0;
	int count = 1;
	while (l < Max_Sample){
		l = l +  (double)(1 / ((double)count + 1));
		for (vector<double>::iterator it = AllSample.begin(); it != AllSample.end(); it++){
			if ( l > *it && AllSample_R.find(*it) == AllSample_R.end() ){
				AllSample_R[*it] = l;
			}
		}
		mMap[l] = count;
		count++;
	}
	for (vector<double>::iterator it = AllSample.begin(); it != AllSample.end(); it++){
		cout << mMap[AllSample_R[*it]] << " card(s)"<< endl;
	}

	return 0;
}