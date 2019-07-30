#include<iostream>

using namespace std;

#define MAX_STAMP_TYPE 100

#define MAX_DFS 4
#define MIN_DFS 0

int stamp[MAX_STAMP_TYPE];
bool tie, none;

int now[MAX_DFS], ans[MAX_DFS], max_stamp;//记录遍历stamp的index,遍历的最大条件：max_stamp最大邮票

int getInfo(int sta[]){//计算sta的优秀值
	int tmp_a = 1, tmp_b = 1, tmp_c = sta[0];//sta是否最优的参数，a决定性最强，b次之，c最弱（若环境中，判断参数更多，则需在此添加更多参数）
	for (int i = 1; i<MAX_DFS && sta[i]>0; i++){//计算sta的优秀值，下面是计算方式
		if (sta[i - 1] != sta[i]) tmp_a++;//取种类数  千位
		tmp_b++;//取总张数  百位
		tmp_c = sta[i - 1]>sta[i] ? sta[i - 1] : sta[i];//取最大值  十位和个位
	}

	return tmp_a * 1000 + (10 - tmp_b) * 100 + tmp_c;
}

void doNeeding(){
	none = false;
	int nowInfo = getInfo(now), ansInfo = getInfo(ans);

	//对相同最优情况需要判断时，选多状态判别，若不许判断，则可以使用bool
	int result = nowInfo > ansInfo ? 2 : ( nowInfo < ansInfo ? 0 : 1);//2表示当前now的遍历情况是最优的解，1表示ans和now的遍历情况一样，0表示原有的ans遍历情况更优
	//bool result = nowInfo >= ansInfo ? true : false;

	if (result == 2){
		memcpy(ans, now, sizeof(now));
		tie = false;
	}
	else if (result == 1){
		tie = true;
	}
	return;
}

//深度优先遍历
void dfs(int power, int count){
	if (power == 0){//遍历到最后
		doNeeding();
		return;
	}
	else if (count >= MAX_DFS){//遍历到边界
		return;
	}
	else if (power < MIN_DFS){//遍历到边界
		return;
	}
	else if (power>max_stamp*(MAX_DFS - count)){//遍历的其他边界条件（环境给定）
		return;
	}
	for (int i = (count>0?now[count-1]:1); i <= stamp[0]; i++){
		now[count] = i;//第count步的index
		dfs(power - stamp[i], count + 1);//进行更深一度的遍历
		now[count] = 0;//完成第count步的遍历，改回遍历前的状态
	}

}

int main(){


	do{
		
		int tmp, i = 1;
		max_stamp = 0;
		memset(stamp, 0, sizeof(stamp));
		while (cin >> tmp && tmp != 0){
			stamp[i++] = tmp;
			max_stamp = max_stamp > tmp ? max_stamp : tmp;
		}
		//记录邮票的type
		stamp[0] = i - 1;

		while (cin >> tmp && tmp != 0){
			tie = false;
			none = true;
			memset(now, 0, sizeof(now));
			memset(ans, 0, sizeof(ans));
			dfs(tmp, 0);
			if (tie)cout << tmp << " (" << getInfo(ans) / 1000 << "): " << "tie" << endl;
			else if (none) cout << tmp << " ---- none" << endl;
			else{
				cout << tmp << " (" << getInfo(ans) / 1000 << "):";
				for (int i = 0; i<4 && ans[i]>0; i++)cout << " " << stamp[ans[i]];
				cout << endl;
			}
		}

	}while (getchar() != EOF);

	return 0;
}