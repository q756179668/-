#include <vector>
#include <string>
#include <stack>
#include <math.h>
#include <algorithm>
#include <sstream>

using namespace std;


/*********************************************************************************************
��ָoffer��1
//��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
//�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�����

*********************************************************************************************/


class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int rows = array.size();
		int cols = array[0].size();
		int i = rows - 1, j = 0;
		while (i >= 0 && j<cols){
			if (target<array[i][j])
				i--;
			else if (target>array[i][j])
				j++;
			else
				return true;
		}
		return false;
	}
};


/*********************************************************************************************
��ָoffer��2
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

*********************************************************************************************/

class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0;
		for (int i = 0; i < length; i++){
			if (str[i] == ' '){
				count++;
			}
		}
		for (int i = length - 1; i >= 0;i--){
			if (str[i] == ' '){
				str[i + 2 * count] = '0';
				str[i + 2 * count - 1] = '2';
				str[i + 2 * count - 2] = '%';
				count--;
			}
			else{
				str[i + 2 * count] = str[i];
			}
			
		}
	}
};

/*********************************************************************************************
��ָoffer��3
����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��

*********************************************************************************************/

struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x):val(x), next(NULL) {
	  }
};
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> mVec(0);
		while (head != nullptr){
			mVec.push_back(head->val);
			head = head->next;
		}
		vector<int> mRVec(0);
		for (vector<int>::reverse_iterator rit = mVec.rbegin(); rit != mVec.rend(); rit++){
			mRVec.push_back(*rit);
		}
		return mRVec;
	}
};


/*********************************************************************************************
��ָoffer��4
����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{ 1, 2, 4, 7, 3, 5, 6, 8 }�������������{ 4, 7, 2, 1, 5, 3, 8, 6 }��
���ؽ�������������
*********************************************************************************************/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		TreeNode* root = reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
		return root;
	}

	TreeNode* reConstructBinaryTree(vector<int> pre, int startPre, int endPre, vector<int> vin,int startIn,int endIn){
		if (startPre > endPre || startIn > endIn){
			return NULL;
		}
		TreeNode* root = new TreeNode(pre[startPre]);

		for (int i = startIn; i <= endIn; i++){
			if (vin[i] == pre[startPre]){
				root->left = reConstructBinaryTree(pre, startPre + 1, startPre + i - startIn, vin, startIn, i - 1);
				root->right = reConstructBinaryTree(pre, i - startIn + startPre + 1, endPre, vin, i + 1, endIn);
				break;
			}
		}
		return root;
	}
};


/*********************************************************************************************
��ָoffer��5
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
*********************************************************************************************/
class Solution
{
public:
	void push(int node) {
		while (!stack2.empty()){
			stack1.push(stack2.top());
			stack2.pop();
		}
		stack1.push(node);
		while (!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
	}

	int pop() {
		int mtop = stack2.top();
		stack2.pop();
		return mtop;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

/*********************************************************************************************
��ָoffer��6
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء� 
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*********************************************************************************************/
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0){
			return 0;
		}
		else if (rotateArray.size() == 1){
			return rotateArray[0];
		}
		for (int i = 1; i < rotateArray.size(); i++){
			if (rotateArray[i] < rotateArray[i-1]){
				return rotateArray[i];
			}
		}
		return 0;
	}
};

/*********************************************************************************************
��ָoffer��7
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����
n<=39
*********************************************************************************************/
class Solution {
public:
	int Fibonacci(int n) {
		if (n <= 1){
			return n;
		}
		int n_1 = 1;
		int n_2 = 0;
		for (int i = 0; i < n - 1; i++){
			int n_22 = n_2;
			n_2 = n_1;
			n_1 = n_1 + n_22;
		}
		return n_1;
	}
};


/*********************************************************************************************
��ָoffer��7
һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
�����������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
*********************************************************************************************/
class Solution {
public:
	int jumpFloor(int number) {
		if (number <= 2){
			return number;
		}
		return jumpFloor(number - 1) + jumpFloor(number-2);
	}
};

/*********************************************************************************************
��ָoffer��8
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
�����������һ��n����̨���ܹ��ж�����������
*********************************************************************************************/
class Solution {
public:
	int jumpFloorII(int number) {
		if (number <= 1){
			return number;
		}
		return jumpFloorII(number-1)*2;
	}
};

/*********************************************************************************************
��ָoffer��9
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
*********************************************************************************************/
class Solution {
public:
	int rectCover(int number) {
		if (number <= 2){
			return number;
		}
		return rectCover(number - 1) + rectCover(number-2);
	}
};

/*********************************************************************************************
��ָoffer��10
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*********************************************************************************************/
class Solution {
public:
	int  NumberOf1(int n) {
		if (n >= 0){
			int count = 0;
			while (n > 0){
				if (n%2 == 1){
					count++;
				}
				n = n / 2;
			}
			return count;
		}
		else{
			n = -n;
			int count = 0;
			while (n > 0){
				if (n % 2 == 0){
					count++;
				}
				n = n / 2;
			}
			return 32 - count;
		}
	}
};

/*********************************************************************************************
��ָoffer��10
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
*********************************************************************************************/
class Solution {
public:
	double Power(double base, int exponent) {
		return pow(base, exponent);
	}
};

/*********************************************************************************************
��ָoffer��11
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
*********************************************************************************************/
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> jArray;
		vector<int> oArray;
		for (vector<int>::iterator it = array.begin(); it != array.end(); it++){
			if (*it%2 == 1){
				jArray.push_back(*it);
			}
			else{
				oArray.push_back(*it);
			}
		}
		array.clear();
		array.insert(array.end(), jArray.begin(), jArray.end());
		array.insert(array.end(), oArray.begin(), oArray.end());
	}
};

/*********************************************************************************************
��ָoffer��12
����һ����������������е�����k�����
*********************************************************************************************/
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		int count = 0;
		if (pListHead == nullptr){
			return nullptr;
		}
		ListNode* mListHead = pListHead;
		while (mListHead != nullptr)
		{
			count++;
			mListHead = mListHead->next;
		}
		if (k > count){
			return nullptr;
		}
		ListNode* kListHead = pListHead;
		for (int i = 0; i < count - k; i++){
			kListHead = kListHead->next;
		}
		return kListHead;
	}
};

/*********************************************************************************************
��ָoffer��13
����һ��������ת��������������ı�ͷ��
*********************************************************************************************/
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		
		if (pHead == nullptr || pHead->next == nullptr){
			return pHead;
		}
		ListNode* nowList = pHead;
		ListNode* preList = nullptr;
		ListNode* nextList;
		while (nowList != nullptr){
			nextList = nowList->next;
			nowList->next = preList;

			preList = nowList;
			nowList = nextList;
		}
		return preList;
	}
};

/*********************************************************************************************
��ָoffer��14
����һ��������ת��������������ı�ͷ��
*********************************************************************************************/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr){
			return pHead2;
		}
		else if (pHead2 == nullptr){
			return pHead1;
		}


		ListNode* resultlist = nullptr;
		if (pHead1->val < pHead2->val){
			resultlist = pHead1;
			resultlist->next = Merge(pHead1->next, pHead2);
		}
		else{
			resultlist = pHead2;
			resultlist->next = Merge(pHead1, pHead2->next);
		}
	
		return resultlist;
	}
};

/*********************************************************************************************
��ָoffer��15
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
*********************************************************************************************/
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != nullptr && pRoot2 != nullptr){
			if (pRoot1->val == pRoot2->val){
				result = Tree1HasTree2(pRoot1, pRoot2);
			}
			if (!result){
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			if (!result){
				result = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return result;
	}

	bool Tree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2){
		if (pRoot1 == nullptr && pRoot2 != nullptr){
			return false;
		}
		if (pRoot2 == nullptr){
			return true;
		}
		if (pRoot1->val != pRoot2->val){
			return false;
		}
		return Tree1HasTree2(pRoot1->left, pRoot2->left) && Tree1HasTree2(pRoot1->right, pRoot2->right);
	}
};

/*********************************************************************************************
��ָoffer��16
���������Ķ�����������任ΪԴ�������ľ���
�������ľ����壺Դ������
	 8
   /  \
  6   10
 / \  / \
5  7 9  11
���������
	 8
   /  \
  10   6
 / \  / \
11 9 7   5
*********************************************************************************************/
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr){
			return;
		}
		if (pRoot->left != nullptr && pRoot->right != nullptr){
			TreeNode* mNode = nullptr;
			mNode = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = mNode;

			Mirror(pRoot->left);
			Mirror(pRoot->right);
		}
		else if (pRoot->left != nullptr && pRoot->right == nullptr){
			pRoot->right = pRoot->left;
			pRoot->left = nullptr;
			Mirror(pRoot->right);
		}
		else if (pRoot->left == nullptr && pRoot->right != nullptr){
			pRoot->left = pRoot->right;
			pRoot->right = nullptr;
			Mirror(pRoot->left);
		}
		else{
			return;
		}
	}
};

/*********************************************************************************************
��ָoffer��17
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
���磬�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
�����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*********************************************************************************************/
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> result;
		if (matrix.size() == 0){
			return result;
		}
		int n = matrix.size();
		int m = matrix[0].size();
		if (m == 0){
			return result;
		}
		int layers = (min(m, n) - 1) / 2 + 1;
		for (int i = 0; i < layers; i++){
			for (int k = i;k < m-i; k++){
				result.push_back(matrix[i][k]);
			}
			for (int k = i + 1;k < n-i; k++){
				result.push_back(matrix[k][m-i-1]);
			}
			for (int k = m - i - 1 -1;(k >= i) && (n-i-1 != i);k--){
				result.push_back(matrix[n-i-1][k]);
			}
			for (int k = n - i - 1 - 1;(k > i) && (m - i - 1) != i;k--){
				result.push_back(matrix[k][i]);
			}
		}
		return result;
	}
};


/*********************************************************************************************
��ָoffer��18
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
*********************************************************************************************/
class Solution {
public:
	void push(int value) {
		if (mStack.empty()){
			minVal = value;
		}
		else{
			if (minVal > value){
				minVal = value;
			}
		}
		mStack.push(value);
	}
	void pop() {
		if (minVal != mStack.top()){
			mStack.pop();
		}
		else{
			mStack.pop();
			vector<int> buff;
			minVal = mStack.top();
			while (!mStack.empty()){
				buff.push_back(mStack.top());
				if (minVal > mStack.top()){
					minVal = mStack.top();
				}
				mStack.pop();
			}
			for (vector<int>::reverse_iterator rit = buff.rbegin(); rit != buff.rend(); rit++){
				mStack.push(*rit);
			}
		}
	}
	int top() {
		mStack.top();
	}
	int min() {
		return minVal;
	}
private: stack<int> mStack;
		 int minVal;
};

/*********************************************************************************************
��ָoffer��19
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ�
��������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵģ�
*********************************************************************************************/
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		int count = pushV.size();
		if (count == 1){
			if (pushV[0] == popV[0]){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			int* rpopV = new int[count];
			for (int i = 0; i < count; i++){
				rpopV[i] = popV[count - i - 1];
			}
			for (int i = 0; i < count-1; i++){
				if (rpopV[i] != pushV[i]){
					if (rpopV[i] != pushV[i + 1]){
						return false;
					}
				}
			}
			return true;
		}
	}
};

/*********************************************************************************************
��ָoffer��20
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
*********************************************************************************************/
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		if (root == nullptr){
			return resultV;
		}
		else{
			resultV.push_back(root->val);
			getNodeDate(root);
			return resultV;
		}
	}
	void getNodeDate(TreeNode* root){
		if (root->left != nullptr && root->right != nullptr){
			resultV.push_back(root->left->val);
			resultV.push_back(root->right->val);
			getNodeDate(root->left);
			getNodeDate(root->right);
		}
		else if (root->left != nullptr && root->right == nullptr){
			resultV.push_back(root->left->val);
			//resultV.push_back(root->right->val);
			getNodeDate(root->left);
			//getNodeDate(root->right);
		}
		else if (root->left == nullptr && root->right != nullptr){
			//resultV.push_back(root->left->val);
			resultV.push_back(root->right->val);
			//getNodeDate(root->left);
			getNodeDate(root->right);
		}
	}

private:
	vector<int> resultV;
};


/*********************************************************************************************
��ָoffer��21
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
����������Yes,�������No���������������������������ֶ�������ͬ��
*********************************************************************************************/
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0){
			return false;
		}
		return IsBST(sequence, 0, sequence.size()-1);
	}
	bool IsBST(vector<int> sequence,int start,int end){
		if (end <= start){
			return true;
		}
		int i = start;
		for (;i < end; i++){
			if (sequence[i] > sequence[end]){
				break;
			}
		}
		for (int j = i; j < end; j++){
			if (sequence[j] < sequence[end]){
				return false;
			}
		}
		return IsBST(sequence,start,i-1) && IsBST(sequence,i,end-1);
	}
};

/*********************************************************************************************
��ָoffer��22
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
*********************************************************************************************/
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == nullptr){
			return VecAll;
		}
		Vec.push_back(root->val);
		expectNumber -= root->val;
		if (expectNumber == 0 && root->left == nullptr && root->right == nullptr){
			vector<int> mVec(Vec);
			VecAll.push_back(mVec);
		}
		FindPath(root->left, expectNumber);
		FindPath(root->right, expectNumber);
		Vec.erase(--Vec.end());
		return VecAll;
	}

private:
	vector<vector<int> > VecAll;
	vector<int> Vec;
};

/*********************************************************************************************
��ָoffer��23
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
���ؽ��Ϊ���ƺ��������head��
��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
*********************************************************************************************/
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		RandomListNode* p = pHead;
		RandomListNode* r = pHead;

		while (p != nullptr){
			RandomListNode* q = new RandomListNode(p->label);
			q->next = p->next;
			p->next = q;
			p = q->next;
		}

		while (r != nullptr){
			RandomListNode* qr = r->next;
			if (r->random != nullptr){
				qr->random = r->random->next;
			}
			r = qr->next;
		}

		RandomListNode* S = new RandomListNode(0);
		RandomListNode* pre = S;
		while (pHead != nullptr){
			RandomListNode* qs = pHead->next;
			pHead->next = qs->next;
			qs->next = S->next;
			S->next = qs;
			S = S->next;
			pHead = pHead->next;
		}
		return pre->next;
	}
};

/*********************************************************************************************
��ָoffer��24
����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
*********************************************************************************************/
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr){
			return pRootOfTree;
		}

		inOder(pRootOfTree);
		
		for (int i = 0; i < sortNode.size()-1; i++){
			sortNode[i]->right = sortNode[i+1];
		}
		for (int i = 1; i < sortNode.size(); i++){
			sortNode[i]->left = sortNode[i - 1];
		}
		return sortNode[0];

	}
	void inOder(TreeNode* node){
		if (node != nullptr){
			inOder(node->left);
			sortNode.push_back(node);
			inOder(node->right);
		}
	}
private:
	vector<TreeNode*> sortNode;
};

/*********************************************************************************************
��ָoffer��25
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
*********************************************************************************************/
class Solution {
public:
	void swap(string& str,int i ,int j){
		char tmp;
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}

	bool isSameOne(string str, int start, int end){
		for (int i = start; i < end; i++){
			if (str[i] == str[end]){
				return true;
			}
		}
		return false;
	}

	void allPermutation(string str, int start, vector<string>& VecStr){
		if (start == str.size()-1){
			VecStr.push_back(str);
		}
		else{
			for (int i = start; i < str.size(); i++){
				if (!isSameOne(str,start,i)){
					swap(str,i,start);
					allPermutation(str,start+1,VecStr);
					swap(str, start, i);
				}
			}
		}
	}

	vector<string> Permutation(string str) {
		vector<string> result;
		if (str.empty() || str.size() == 0){
			return result;
		}
		allPermutation(str,0,result);
		sort(result.begin(),result.end());
		return result;
	}
};

/*********************************************************************************************
��ָoffer��26
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ�
�������鳤�ȵ�һ�룬������2����������������0��
*********************************************************************************************/
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		if (count(numbers.begin(), numbers.end(), numbers[(numbers.size() + 1) / 2 - 1]) >= (numbers.size() + 1) / 2){
			return numbers[(numbers.size() + 1) / 2 - 1];
		}
		else{
			return 0;
		}
	}
};

/*********************************************************************************************
��ָoffer��27
����n���������ҳ�������С��K������
��������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
*********************************************************************************************/
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		

		vector<int> resultK;
		if (k > input.size()){
			return resultK;
		}
		sort(input.begin(), input.end());

		for (int i = 0; i < k ; i++){
			resultK.push_back(input[i]);
		}
		return resultK;
	}
};

/*********************************************************************************************
��ָoffer��28
HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
��������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,
������ȫΪ������ʱ��,����ܺý��������,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
��һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)
*********************************************************************************************/
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int nowVal = array[0];
		int maxVal = array[0];
		for (int i = 1;i < array.size(); i++){
			nowVal += array[i];
			if (nowVal < array[i]){
				nowVal = array[i];
			}
			if (nowVal > maxVal){
				maxVal = nowVal;
			}
		}
		return maxVal;
	}
};

/*********************************************************************************************
��ָoffer��29
���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����
Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,���Ƕ��ں�����������û���ˡ�
ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�������1 �� n ��1���ֵĴ�������
*********************************************************************************************/
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;
		for (int i = 1; i <= n; i++){
			int num = i;
			while (num > 0){
				if (num%10 == 1){
					count++;
				}
				num = num / 10;
			}
		}
		return count;
	}
};

/*********************************************************************************************
��ָoffer��30
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
*********************************************************************************************/
class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		vector<long> vecL;
		if (numbers.size() == 0){
			return "";
		}
		sort(numbers.begin(), numbers.end(),cmp);
		string str_min = "";
		for (int i = 0; i < numbers.size(); i++){
			str_min += to_string(numbers[i]);
		}
		return str_min;
	}
	static bool cmp(int valA, int valB){
		string str1 = to_string(valA) + to_string(valB);
		string str2= to_string(valB) + to_string(valA);
		return str1 < str2;
	}

};

/*********************************************************************************************
��ָoffer��31
��ֻ����������2��3��5��������������Ugly Number����
����6��8���ǳ�������14���ǣ���Ϊ������������7�� 
ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
*********************************************************************************************/
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index <= 0){
			return 0;
		}
		vector<int> result(index);
		int count = 0;
		int i2 = 0;
		int i3 = 0;
		int i5 = 0;
		result[0] = 1;
		int tmp = 0;
		while (count < (index - 1))
		{
			tmp = min(result[i2] * 2, min(result[i3] * 3, result[i5] * 5));
			if (tmp == result[i2] * 2){
				i2++;
			}
			if (tmp == result[i3] * 3){
				i3++;
			}
			if (tmp == result[i5] * 5){
				i5++;
			}
			result[++count] = tmp;
		}
		return result[index - 1];
	}
};

/*********************************************************************************************
��ָoffer��32
��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,
����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��
*********************************************************************************************/
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.empty()){
			return -1;
		}
		for (int i = 0; i < str.size(); i++){
			bool flg = true;
			for (int j = 0; j < str.size(); j++){
				if (j != i){
					if (str[i] == str[j]){
						flg = false;
						break;
					}
				}
			}
			if (flg){
				return i;
			}
		}
		return -1;
	}
};

/*********************************************************************************************
��ָoffer��33
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
����һ������,�����������е�����Ե�����P������P��1000000007ȡģ�Ľ������� 
�����P%1000000007
*********************************************************************************************/
class Solution {
public:
	int InversePairs(vector<int> data) {
		if (!data.empty()){
			mergeSort(data,0,data.size()-1);
		}
		return count;
	}

	void mergeSort(vector<int>& vec, int start, int end){
		if (start >= end){
			return;
		}
		int mid = (start + end) >> 1;
		mergeSort(vec, start, mid);
		mergeSort(vec, mid + 1, end);
		merge(vec,start,mid,end);

	}

	void merge(vector<int>& vec, int start,int mid, int end ){
		vector<int> tmpVec(end - start + 1);

		int i = start, j = mid + 1, k = 0;
		while (i <= mid && j <= end){
			if (vec[i] <= vec[j]){
				tmpVec[k++] = vec[i++];
			}
			else{
				tmpVec[k++] = vec[j++];
				count += (mid - i + 1);
				count %= 1000000007;
			}
		}
		while (i <= mid){
			tmpVec[k++] = vec[i++];
		}
		while (j <= end){
			tmpVec[k++] = vec[j++];
		}
		for (k = 0; k < tmpVec.size(); k++){
			vec[start + k] = tmpVec[k];
		}
	}
private:
	int count = 0;
};

/*********************************************************************************************
��ָoffer��34
�������������ҳ����ǵĵ�һ��������㡣
*********************************************************************************************/
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr){
			return nullptr;
		}

		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		int count1 = 0;
		int count2 = 0;
		while (p1 != nullptr){
			count1++;
			p1 = p1->next;
		}
		while (p2 != nullptr){
			count2++;
			p2 = p2->next;
		}
		int dis = count1 - count2;
		if (dis > 0){
			while (dis > 0){
				pHead1 = pHead1->next;
				dis--;
			}
			while (pHead1 != pHead2){
				pHead1 = pHead1->next;
				pHead2 = pHead2->next;
			}
			return pHead1;
		}
		else{
			while (dis < 0){
				pHead2 = pHead2->next;
				dis--;
			}
			while (pHead1 != pHead2){
				pHead1 = pHead1->next;
				pHead2 = pHead2->next;
			}
			return pHead1;
		}
		return nullptr;
	}
};

/*********************************************************************************************
��ָoffer��35
ͳ��һ�����������������г��ֵĴ�����
*********************************************************************************************/
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.empty()){
			return 0;
		}
		int startIndex = getStartIndex(data,k,0,data.size()-1);
		int endIndex = getEndIndex(data, k, 0, data.size() - 1);

		if (startIndex == -1 && endIndex == -1){
			return 0;
		}
		int result = endIndex - startIndex + 1;
		return result;
	}

	int getStartIndex(vector<int> data, int k, int start, int end){
		if (start == end){
			if (data[start] == k){
				return start;
			}
			else{
				return -1;
			}
		}
		int mid = (start + end ) / 2;
		int startIndex = 0;
		if (data[mid] < k){
			startIndex = getStartIndex(data,k,mid+1,end);
		}
		else{
			startIndex = getStartIndex(data, k, start, mid);
		}
		return startIndex;
	}

	int getEndIndex(vector<int> data, int k, int start, int end){
		if (start == end){
			if (data[start] == k){
				return start;
			}
			else{
				return -1;
			}
		}
		int mid = (start + end + 1) / 2;
		int EndIndex = 0;
		if (data[mid] > k){
			EndIndex = getEndIndex(data, k, start, mid - 1);
		}
		else{
			EndIndex = getEndIndex(data, k, mid, end);
		}
		return EndIndex;
	}
};
/*********************************************************************************************
��ָoffer��38
����һ�ö����������������ȡ�
�Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
*********************************************************************************************/
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		int nowDeep = 0;
		if (pRoot == nullptr){
			return 0;
		}
		getMaxDeep(pRoot, nowDeep);
		return MaxDeep;
	}

	void getMaxDeep(TreeNode* pRoot,int nowDeep){
		if (pRoot == nullptr){
			if (nowDeep > MaxDeep){
				MaxDeep = nowDeep;
			}
			return;
		}
		if (pRoot->left == nullptr && pRoot->right == nullptr){
			if (nowDeep + 1 > MaxDeep){
				MaxDeep = nowDeep + 1;
			}
		}
		nowDeep++;
		if (pRoot->left != nullptr){
			getMaxDeep(pRoot->left,nowDeep);
		}
		if (pRoot->right != nullptr){
			getMaxDeep(pRoot->right, nowDeep);
		}
	}

private:
	int MaxDeep = 0;
};

/*********************************************************************************************
��ָoffer��39
����һ�ö��������жϸö������Ƿ���ƽ���������
*********************************************************************************************/
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == nullptr){
			return true;
		}
		int Deep = 0;
		getMaxDeep(pRoot->left, Deep);
		int leftMaxDeep = MaxDeep;
		MaxDeep = 0;
		Deep = 0;
		getMaxDeep(pRoot->right, Deep);
		int rightMaxDeep = MaxDeep;
		if (abs(leftMaxDeep - rightMaxDeep) <= 1){
			return true;
		}
		else{
			return false;
		}
	}

	void getMaxDeep(TreeNode* pRoot, int nowDeep){
		if (pRoot == nullptr){
			if (nowDeep > MaxDeep){
				MaxDeep = nowDeep;
			}
			return;
		}
		if (pRoot->left == nullptr && pRoot->right == nullptr){
			if (nowDeep + 1 > MaxDeep){
				MaxDeep = nowDeep + 1;
			}
		}
		nowDeep++;
		if (pRoot->left != nullptr){
			getMaxDeep(pRoot->left, nowDeep);
		}
		if (pRoot->right != nullptr){
			getMaxDeep(pRoot->right, nowDeep);
		}
	}

private:
	int MaxDeep = 0;
};

/*********************************************************************************************
��ָoffer��40
����һ�ö��������жϸö������Ƿ���ƽ���������
*********************************************************************************************/
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		bool getFrist = false;
		for (vector<int>::iterator it = data.begin(); it != data.end(); it++){
			if (count(data.begin(), data.end(), *it) == 1){
				if (!getFrist){
					getFrist = true;
					*num1 = *it;
				}
				else{
					*num2 = *it;
				}
			}
		}

	}
};

/*********************************************************************************************
��ָoffer��41
С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22��
���ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? 
Good Luck!
*********************************************************************************************/
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > result;
		if (sum == 1){
			return result;
		}
		int n = (int)ceil((sqrt(8 * sum + 1) - 1) / 2);
		int tmp = 0;
		int num = 0;
		for (int i = n; i > 1; i--){
			tmp = (i + 1)*i / 2;
			if ((sum - tmp) % i == 0){
				vector<int> vec;
				num = (sum - tmp) / i;
				for (int a = 1; a<=i; a++){
					vec.push_back(num + a);
				}
				result.push_back(vec);
			}
		}
		return result;
	}
};

/*********************************************************************************************
��ָoffer��42
����һ����������������һ������S���������в�����������
ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
�������:
��Ӧÿ�����԰����������������С���������
*********************************************************************************************/
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> result;

		if (array.empty()){
			return result;
		}

		if (sum/2 < array[0]){
			return result;
		}

		int minV = 9999999;
		vector<int> index(2);
		for (int i = 0; i < array.size(); i++){
			int otherNum = sum - array[i];
			for (int j = i + 1; j < array.size(); j++){
				if (array[j] == otherNum){
					if (minV > array[j]*array[i] ){
						minV = array[j] * array[i];
						index[0] = i;
						index[1] = j;
					}
				}
				if (otherNum < array[j]){
					break;
				}
			}
		}

		if (minV == 9999999){
			return result;
		}
		result.push_back(array[index[0]]);
		result.push_back(array[index[1]]);
		return result;
	}
};

/*********************************************************************************************
��ָoffer��43
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
����һ���������ַ�����S���������ѭ������Kλ������������
���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����
�ǲ��Ǻܼ򵥣�OK���㶨����
*********************************************************************************************/
class Solution {
public:
	string LeftRotateString(string str, int n) {
		string preN = str.substr(0,n);
		str.erase(0,n);
		str.insert(str.end(), preN.begin(), preN.end());
		return str;
	}
};
/*********************************************************************************************
��ָoffer��44
ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼�����磬��student. a am I����
��������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����
Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
*********************************************************************************************/
class Solution {
public:
	string ReverseSentence(string str) {
		vector< string> allWord = split(str, " ");
		string output = "";
		if (allWord.size() == 0 && !str.empty()){
			return  str;
		}
		if (allWord.empty()){
			return output;
		}

		for (int i = 0; i < allWord.size() - 1; i++){
			output += allWord[allWord.size() - 1 - i] + " ";
		}
		output += allWord[0];
		return output;
	}

	//�ַ����ָ��
	vector< string> split(string str, string pattern)
	{
		vector<string> ret;
		if (pattern.empty()) return ret;
		size_t start = 0, index = str.find_first_of(pattern, 0);
		while (index != str.npos)
		{
			if (start != index)
				ret.push_back(str.substr(start, index - start));
			start = index + 1;
			index = str.find_first_of(pattern, start);
		}
		if (!str.substr(start).empty())
			ret.push_back(str.substr(start));
		return ret;
	}
};

/*********************************************************************************************
��ָoffer��45
LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...
��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���
������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....
LL��������,��������,������\С �����Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13��
�����5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����LL����ȥ��������Ʊ���� 
����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Σ� ����������˳�Ӿ����true����������false��
Ϊ�˷������,�������Ϊ��С����0��
*********************************************************************************************/
class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.empty()){
			return false;
		}
		int ZeroCount = 0;
		for (int i = 0; i < numbers.size(); i++){
			if (numbers[i] == 0){
				ZeroCount++;
			}
		}
		if (ZeroCount == 4){
			return true;
		}
		sort(numbers.begin(), numbers.end());
		for (int i = ZeroCount; i < numbers.size() - 1; i++){
			if ((numbers[i] - numbers[i + 1] + 1 + ZeroCount) < 0){
				return false;
			}
			else{
				ZeroCount = numbers[i] - numbers[i + 1] + 1 + ZeroCount;
			}
		}
		if (ZeroCount == 0){
			return true;
		}
		else{
			return false;
		}
	}
};

/*********************************************************************************************
��ָoffer��46
ÿ����һ��ͯ��,ţ�Ͷ���׼��һЩС����ȥ�����¶�Ժ��С����,����������ˡ�
HF��Ϊţ�͵�����Ԫ��,��ȻҲ׼����һЩС��Ϸ������,�и���Ϸ��������:����,��С������Χ��һ����Ȧ��
Ȼ��,�����ָ��һ����m,�ñ��Ϊ0��С���ѿ�ʼ������
ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,
���Ҳ��ٻص�Ȧ��,��������һ��С���ѿ�ʼ,����0...m-1����....������ȥ....ֱ��ʣ�����һ��С����,
���Բ��ñ���,�����õ�ţ������ġ�����̽���ϡ���ذ�(��������Ŷ!!^_^)��
������������,�ĸ�С���ѻ�õ������Ʒ�أ�(ע��С���ѵı���Ǵ�0��n-1)
*********************************************************************************************/
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		/*int* allChild = new int[n];
		memset(allChild,0,n*sizeof(int));*/
		if (n == 0){
			return -1;
		}
		vector<int> allChild(n);
		int count = n;
		int index = 0;
		while (count != 1){
			int passNum = 0;
			while (passNum < m){
				if (allChild[index++] == 0){
					passNum++;
				}
				if (index >= n){
					index = index - n;
				}
			}
			if (index == 0){
				allChild[n - 1] = 1;
			}
			else{
				allChild[index - 1] = 1;
			}
			count--;
		}
		int i = 0;
		for (;i < n; i++){
			if (allChild[i] == 0){
				break;
			}
		}
		return i;
	}		
};

/*********************************************************************************************
��ָoffer��47
��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
*********************************************************************************************/
class Solution {
public:
	int Sum_Solution(int n) {
		int sum = n;
		n && (sum += Sum_Solution(n - 1));
		return sum;
	}
};

/*********************************************************************************************
��ָoffer��48
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
*********************************************************************************************/
class Solution {
public:
	int Add(int num1, int num2)
	{
		int jinwei = (num1&num2) << 1;
		int baoliu = (num1^num2);
		while (jinwei&baoliu){
			num1 = jinwei;
			num2 = baoliu;
			jinwei = (num1&num2) << 1;
			baoliu = (num1^num2);
		}
		return jinwei|baoliu;
	}
};

/*********************************************************************************************
��ָoffer��49
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
*********************************************************************************************/
class Solution {
public:
	int StrToInt(string str) {
		int num = 0;
		if (str[0] >= '0' && str[0] <= '9'){
			for (int i = 0; i < str.size(); i++){
				if (str[i] >= '0' && str[i] <= '9'){
					num += ((int)(str[i] - '0') * pow(10, str.size() - 1 - i));
				}
				else{
					return 0;
				}
			}
		}
		else if (str[0] == '+'){
			for (int i = 1; i < str.size(); i++){
				if (str[i] >= '0' && str[i] <= '9'){
					num += ((int)(str[i] - '0') * pow(10, str.size() - 1 - i));
				}
				else{
					return 0;
				}
			}
		}
		else if (str[0] == '-'){
			for (int i = 1; i < str.size(); i++){
				if (str[i] >= '0' && str[i] <= '9'){
					num += ((int)(str[i] - '0') * pow(10, str.size() - 1 - i));
				}
				else{
					return 0;
				}
			}
			num = -num;
		}
		return num;
	}
};

/*********************************************************************************************
��ָoffer��50
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
*********************************************************************************************/
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		for (int i = 0; i < length; i++){
			for (int j = i+1; j < length; j++){
				if (numbers[i] == numbers[j]){
					*duplication = numbers[i];
					return true;
				}
			}
		}
		return false;
	}
};

/*********************************************************************************************
��ָoffer��51
����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]��
����ʹ�ó�����
*********************************************************************************************/
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> B(A.size());
		if (A.empty()){
			return B;
		}
		vector<int> B_0_i_1(A.size(),1);
		vector<int> B_i_1_end(A.size(), 1);
		for (int i = 1; i < A.size(); i++){
			B_0_i_1[i] = B_0_i_1[i - 1] * A[i-1];
		}
		for (int i = A.size() - 2; i >= 0; i--){
			B_i_1_end[i] = B_i_1_end[i + 1] * A[i + 1];
		}
		for (int i = 0; i < A.size(); i++){
			B[i] = B_0_i_1[i] * B_i_1_end[i];
		}
		return B;
	}
};

/*********************************************************************************************
��ָoffer��52
��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� 
�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
*********************************************************************************************/
class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (str == nullptr || pattern == nullptr){
			return false;
		}
		int strIndex = 0;
		int patternIndex = 0;
		return matchCore(str,strIndex,pattern,patternIndex);
	}

	bool matchCore(string str, int strIndex, string pattern, int patternIndex){
		if (strIndex == str.size() && patternIndex == pattern.size()){
			return true;
		}
		if (strIndex != str.size() && patternIndex == pattern.size()){
			return false;
		}
		if (patternIndex + 1 < pattern.size() && pattern[patternIndex + 1] == '*'){
			if ((strIndex < str.size() && pattern[patternIndex] == str[strIndex]) || (pattern[patternIndex] == '.' && strIndex != str.size())){
				return matchCore(str, strIndex, pattern, patternIndex + 2) 
					|| matchCore(str, strIndex + 1, pattern, patternIndex + 2)
					|| matchCore(str, strIndex + 1, pattern, patternIndex);
			}
			else{
				return matchCore(str, strIndex, pattern, patternIndex + 2);
			}
		}
		if ((strIndex != str.size() && pattern[patternIndex] == str[strIndex]) || (pattern[patternIndex] == '.' && strIndex != str.size())){
			return matchCore(str, strIndex + 1, pattern, patternIndex + 1);
		}
		return false;
	}
};

/*********************************************************************************************
��ָoffer��53
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ�� 
����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
PS:JAVAд���򵥣���������ֱ������ת������ת��ʧ�ܵ��쳣��
*********************************************************************************************/
class Solution {
public:
	bool isNumeric(char* string)
	{
		bool flg_point = false;
		bool flg_E = false;
		bool flg_sign = false;
		for (int i = 0; i < strlen(string); i++){
			if (string[i] == 'E' || string[i] == 'e'){
				if (flg_E){
					return false;
				}
				if (i == strlen(string)-1){
					return false;
				}
				flg_E = true;
			}
			else if (string[i] == '+' || string[i] == '-'){
				if (flg_sign){
					return false;
				}
				if (i != 0 && (string[i - 1] != 'E' && string[i - 1] != 'e')){
					return false;
				}
				if (i != 0){
					flg_sign = true;
				}
			}
			else if (string[i] == '.'){
				if (flg_point){
					return false;
				}
				if (flg_E){
					return false;
				}
				flg_point = true;
			}
			else if (string[i] < '0' || string[i] > '9'){
				return false;
			}
		}
		return true;
	}
};

/*********************************************************************************************
��ָoffer��54
��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
*********************************************************************************************/
class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		bool flg_Is = false;
		for (int i = 0; i < mStrCount.size(); i++){
			if (mStrCount[i].Str == ch){
				flg_Is = true;
				mStrCount[i].Count++;
			}
		}
		if (!flg_Is){
			StrCount chStrCount(1,ch);
			mStrCount.push_back(chStrCount);
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		for (vector<StrCount>::iterator it = mStrCount.begin(); it != mStrCount.end(); it++){
			if (it->Count == 1){
				return it->Str;
			}
		}
		return '#';
	}
private:
	struct StrCount {
		int Count;
		char Str;
		StrCount(int x,char str) :
			Count(x), Str(str) {
		}
	};
	vector<StrCount> mStrCount;
};

/*********************************************************************************************
��ָoffer��55
��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
*********************************************************************************************/
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == nullptr){
			return pHead;
		}
		bool flg_find = false;
		for (vector<ListNode*>::iterator it = mVec.begin(); it != mVec.end(); it++){
			if (*it == pHead){
				flg_find = true;
				break;
			}
		}
		if (flg_find){
			return pHead;
		}
		else{
			mVec.push_back(pHead);
		}

		return EntryNodeOfLoop(pHead->next);
	}
private:
	vector<ListNode*> mVec;
};

/*********************************************************************************************
��ָoffer��56
��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
*********************************************************************************************/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode*

		if (pHead){

		}
	}
};