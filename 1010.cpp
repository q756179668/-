#include<iostream>

using namespace std;

#define MAX_STAMP_TYPE 100

#define MAX_DFS 4
#define MIN_DFS 0

int stamp[MAX_STAMP_TYPE];
bool tie, none;

int now[MAX_DFS], ans[MAX_DFS], max_stamp;//��¼����stamp��index,���������������max_stamp�����Ʊ

int getInfo(int sta[]){//����sta������ֵ
	int tmp_a = 1, tmp_b = 1, tmp_c = sta[0];//sta�Ƿ����ŵĲ�����a��������ǿ��b��֮��c�������������У��жϲ������࣬�����ڴ���Ӹ��������
	for (int i = 1; i<MAX_DFS && sta[i]>0; i++){//����sta������ֵ�������Ǽ��㷽ʽ
		if (sta[i - 1] != sta[i]) tmp_a++;//ȡ������  ǧλ
		tmp_b++;//ȡ������  ��λ
		tmp_c = sta[i - 1]>sta[i] ? sta[i - 1] : sta[i];//ȡ���ֵ  ʮλ�͸�λ
	}

	return tmp_a * 1000 + (10 - tmp_b) * 100 + tmp_c;
}

void doNeeding(){
	none = false;
	int nowInfo = getInfo(now), ansInfo = getInfo(ans);

	//����ͬ���������Ҫ�ж�ʱ��ѡ��״̬�б��������жϣ������ʹ��bool
	int result = nowInfo > ansInfo ? 2 : ( nowInfo < ansInfo ? 0 : 1);//2��ʾ��ǰnow�ı�����������ŵĽ⣬1��ʾans��now�ı������һ����0��ʾԭ�е�ans�����������
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

//������ȱ���
void dfs(int power, int count){
	if (power == 0){//���������
		doNeeding();
		return;
	}
	else if (count >= MAX_DFS){//�������߽�
		return;
	}
	else if (power < MIN_DFS){//�������߽�
		return;
	}
	else if (power>max_stamp*(MAX_DFS - count)){//�����������߽�����������������
		return;
	}
	for (int i = (count>0?now[count-1]:1); i <= stamp[0]; i++){
		now[count] = i;//��count����index
		dfs(power - stamp[i], count + 1);//���и���һ�ȵı���
		now[count] = 0;//��ɵ�count���ı������Ļر���ǰ��״̬
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
		//��¼��Ʊ��type
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