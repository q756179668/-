#include<stdio.h>
#include<string.h>
int sticks[70], book[70];//һ����ľ����һ������Ƿ�ʹ��
int n, len, num;//len�Ǻϲ���ÿ��ľ���ĳ��ȣ�num�Ǻϲ����ľ����Ŀ
void quicksort(int left, int right){
	if (left>right)
		return;
	int temp = sticks[left], i = left, j = right;
	while (i != j){
		while (sticks[j] <= temp&&j>i)
			j--;
		while (sticks[i] >= temp&&j>i)
			i++;
		if (i<j){
			int t = sticks[i];
			sticks[i] = sticks[j];
			sticks[j] = t;
		}
	}
	sticks[left] = sticks[i];
	sticks[i] = temp;
	quicksort(left, i - 1);
	quicksort(i + 1, right);
}
int dfs(int cur, int k, int cnt){//cur�����ںϲ���ľ���ĳ��ȣ�k��ľ�����±꣬cnt�Ǻϲ��õ�ľ����
	if (cnt == num)//���Ҫ������
		return 1;
	if (cur == len)//�ϲ���һ��ľ�������
		return dfs(0, 0, cnt + 1);
	int i, pre = 0;//i��ľ���±꣬pre�����ظ�ľ��
	for (i = k; i<n; i++){
		if (book[i] == 0 && sticks[i] + cur <= len&&sticks[i] != pre){//1
			pre = sticks[i];
			book[i] = 1;
			if (dfs(sticks[i] + cur, i + 1, cnt))//2
				break;
			book[i] = 0;
			if (k == 0)//3
				return 0;
		}
	}
	if (i == n)
		return 0;
	else
		return 1;
}
int main(){
	while (scanf("%d", &n) != EOF&&n){
		int sum = 0;//�ܳ���
		for (int i = 0; i<n; i++){
			scanf("%d", &sticks[i]);
			sum += sticks[i];
		}
		quicksort(0, n - 1);//ע��Ҫ�Ӵ�С������Ϊ�ϲ���ľ���ĳ���һ������ԭ�����
		for (len = sticks[0]; len <= sum / 2; len++){//��֦�������ĳ��ȿ�ʼö�٣��������sum/2�鲢Ϊ�˺ϳ�һ��ľ�������
			if (sum%len == 0){//�������ܳ������ŷ���Ҫ��
				num = sum / len;
				memset(book, 0, sizeof(book));
				if (dfs(0, 0, 0))
					break;
			}
		}
		if (len>sum / 2)//һ��ľ�������
			printf("%d\n", sum);
		else
			printf("%d\n", len);
	}
	return 0;
}