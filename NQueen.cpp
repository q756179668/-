#include "NQueen.h"
#include<iostream>
using namespace std;


void main(){
	NQueen mNQueen = *(new NQueen(13));
	//mNQueen.FindNQueen(0);
	mNQueen.upperlim = (mNQueen.upperlim << 13) - 1;
	mNQueen.FindNQueen(0, 0, 0);
	cout << mNQueen.count << endl;
	cout << mNQueen.mAllArrList.size()<<endl;
	return;
}