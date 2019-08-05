//#include <iostream>
//#include <iomanip>  
//#include <math.h>
//
//using namespace std;
//
//int main(){
//
//	float fNum;
//	cin >> fNum;
//	if (fNum == 1){
//		return 0;
//	}
//	float result = 0.061217*pow(fNum, 10) - 0.30551*pow(fNum, 9) + 0.65361*pow(fNum, 8) - 0.78091 * pow(fNum, 7) + 0.56832 * pow(fNum, 6) - 0.25753 * pow(fNum, 5) + 40.442*pow(fNum, 4)
//										- 36.83*pow(fNum, 3) + 0.37889*pow(fNum, 2) + 0.38547 * fNum + 3.052100;
//
//	cout << fixed << setprecision(6) << result << endl;
//
//	return 0;
//}
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> arraylisChange(vector<int> array){
//	int len = array.size();
//	int newlength = len * 2 - 1;
//	vector<int> res(newlength);
//	for (int i = 0; i < len; i++) {
//		res[2 * i] = array[i];
//		if (i != len - 1) {
//			res[2 * i + 1] = array[i] + array[i + 1];
//		}
//	}
//	return res;
//}
//
//int r = 1;
//int c = 1;
////找位置
//void target(int p, int q){
//	//int r = 1, c = 1;  //行、列
//	int initialSize = 3;
//	vector<int> top (initialSize);
//	vector<int> bottom (initialSize);
//	top[0] = 0; top[1] = 1; top[2] = 1;
//	bottom[0] = 1; bottom[1] = 0; bottom[2] = 0;
//	bool isFind = false;
//	int row = 0;
//	while (!isFind){
//		for (int i = 1; i < top.size(); i = i + 2) {
//			if (top[i] == p && bottom[i] == q){
//				isFind = true;
//				r = row; 
//				c = (i + 1) / 2;
//				break;
//			}
//		}
//		top = arraylisChange(top);
//		bottom = arraylisChange(bottom);
//		row++;
//	}
//	//int result[2] = { r, c };
//	//return  result;
//}

//
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<vector<int>> Ord(vector<vector<int>> a, int b) {
//	vector<int> temp (4);
//	temp = a[b];
//	vector<int> temp1 (4);
//	for (int i = a.size() - 1; i >= b; i--) {
//		temp1 = a[i];
//		a[i] = temp;
//		temp = temp1;
//	}
//	return a;
//}
//
//int main(){
//
//	int N, M;
//
//	cin >> N >> M;
//	vector<vector<int>> WinSiz (N);
//	vector<vector<int>> CliPos(M);
//	for (int i = 0; i < N; i++) {
//		WinSiz[i] = {0,0,0,0,0};
//		WinSiz[i][4] = i + 1;
//		for (int j = 0; j < 4; j++) {
//			cin >> WinSiz[i][j];
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		CliPos[i] = { 0, 0 };
//		for (int j = 0; j < 2; j++) {
//			cin >>CliPos[i][j];
//		}
//	}
//
//	//循环进行M次范围判定
//	vector<int> ID (M);
//	for (int i = 0; i < M; i++) {
//		for (int j = N - 1; j >= 0; j--) {
//			if ((CliPos[i][0] >= WinSiz[j][0]) &&
//				(CliPos[i][0] <= (WinSiz[j][0] + WinSiz[j][2])) &&
//				(CliPos[i][1] >= WinSiz[j][1]) &&
//				(CliPos[i][1] <= (WinSiz[j][1] + WinSiz[j][3]))) {
//				ID[i] = WinSiz[j][4];
//				if (j != (N - 1)) {
//					WinSiz = Ord(WinSiz, j);
//				}
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < M; i++){
//		if (ID[i] == 0) {
//			ID[i] = -1;
//		}
//		cout << (ID[i]) << endl;
//	}
//	
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <math.h>
//
//using namespace std;

//vector<int>Aplayer;
//vector<int>Bplayer;
//
//int mMax = 0;
//
//int getMax(vector<int> player){
//
//	if (player.size() == 0){
//		return 0;
//	}
//
//	int sum = 0;
//	sum += abs(player[0] - 0);
//	for (int i = 1; i < player.size(); i++){
//		sum += abs(player[i] - player[i-1]);
//	}
//	return sum;
//}
//
//void dfs(vector<int> nowNums, bool IsA, vector<int> nowAplayer, vector<int> nowBplayer ){
//
//	
//
//	if (nowNums.empty()){
//		int maxDFs = getMax(nowAplayer);
//		if (maxDFs> mMax){
//			mMax = maxDFs;
//			Aplayer = nowAplayer;
//			Bplayer = nowBplayer;
//		}
//		return;
//	}
//	vector<int> nowAplayer_dfs(nowAplayer);
//	vector<int> nowBplayer_dfs(nowBplayer);
//	
//		if (IsA){
//
//			if (nowNums.front() >= nowNums.back()){
//				nowAplayer_dfs.push_back(nowNums.front());
//				nowNums.erase(nowNums.begin());
//				dfs(nowNums, false, nowAplayer_dfs, nowBplayer_dfs);
//				nowAplayer_dfs.pop_back();
//			}
//			else{
//				nowAplayer_dfs.push_back(nowNums[nowNums.size() - 1]);
//				nowNums.pop_back();
//				dfs(nowNums, false, nowAplayer_dfs, nowBplayer_dfs);
//
//				nowAplayer_dfs.pop_back();
//			}
//		}
//		else{
//			if (nowNums.front() >= nowNums.back()){
//				nowBplayer_dfs.push_back(nowNums.front());
//				nowNums.erase(nowNums.begin());
//				dfs(nowNums, true, nowAplayer_dfs, nowBplayer_dfs);
//				nowBplayer_dfs.pop_back();
//			}
//			else{
//				nowBplayer_dfs.push_back(nowNums[nowNums.size() - 1]);
//				nowNums.pop_back();
//
//				dfs(nowNums, true, nowAplayer_dfs, nowBplayer_dfs);
//				nowBplayer_dfs.pop_back();
//			}
//		}
//	
//
//}
//
//int main(){
//	int N;
//	cin >> N;
//	vector<int>allNum;
//	for (int i = 0; i < N; i++){
//		int Ai;
//		cin >> Ai;
//		allNum.push_back(Ai);
//	}
//
//	vector<int>nowAplayer;
//	vector<int>nowBplayer;
//
//	dfs(allNum,true,nowAplayer,nowBplayer);
//
//	cout << getMax(Aplayer) << " " << getMax(Bplayer) << endl;
//
//	return 0;
//}


#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale>
#include <codecvt>

using namespace std;

std::string UnicodeToAscii(const std::wstring str)
{
	int	iTextLen = WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
	std::vector<char> vecText(iTextLen, '\0');
	::WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, &(vecText[0]), iTextLen, NULL, NULL);

	std::string strText = &(vecText[0]);

	return strText;
}

std::string UTF8ToString(const std::string & utf8Data)
{
	//先将UTF-8转换成Unicode
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	std::wstring wString = conv.from_bytes(utf8Data);
	//在转换成string
	return UnicodeToAscii(wString);
}


int main(){

	int a = 8;
	float y = 4.97;
	float x = 2.7;

	float result = x + a % 3 * (int)(x + y) % 5 / 3;

	int W, XE, YE, XC, YC, PX, PY;
	const int PictureNums = 20;
	int PictureX[PictureNums];
	int PictureY[PictureNums];

	cin >> W >> XE >> YE >> XC >> YC >> PX >> PY;

	for (int i = 0; i < PictureNums; i++){
		cin >> PictureX[i] >> PictureY[i];
	}
	string UTF8data;
	cin >> UTF8data;
	string strData = UTF8ToString(UTF8data);
	
	int nowX = 0;
	int nowY = 0;

	for (int i = 0; i < strData.size(); i++){
		if (strData[i] != '#'){
			nowX += XE;
		}
		int nowH = YE;
		if (nowX >= W){
			nowX -= W;
			nowY += YE;
		}
	}

	return 0;

}