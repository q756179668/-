#include<stdio.h>
#include<string.h>
int sticks[70], book[70];//一个存木棍，一个标记是否使用
int n, len, num;//len是合并后每根木棍的长度，num是合并后的木棍数目
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
int dfs(int cur, int k, int cnt){//cur是正在合并的木棍的长度，k是木棍的下标，cnt是合并好的木棍数
	if (cnt == num)//完成要求的情况
		return 1;
	if (cur == len)//合并好一根木棍的情况
		return dfs(0, 0, cnt + 1);
	int i, pre = 0;//i是木棍下标，pre保存重复木棍
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
		int sum = 0;//总长度
		for (int i = 0; i<n; i++){
			scanf("%d", &sticks[i]);
			sum += sticks[i];
		}
		quicksort(0, n - 1);//注意要从大到小排序，因为合并后木棍的长度一定大于原来最长的
		for (len = sticks[0]; len <= sum / 2; len++){//剪枝，从最大的长度开始枚举，这里大于sum/2归并为了合成一根木棍的情况
			if (sum%len == 0){//长度是总长因数才符合要求
				num = sum / len;
				memset(book, 0, sizeof(book));
				if (dfs(0, 0, 0))
					break;
			}
		}
		if (len>sum / 2)//一根木棍的情况
			printf("%d\n", sum);
		else
			printf("%d\n", len);
	}
	return 0;
}