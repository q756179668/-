#include <vector>
#include <string>
#include <stack>
#include <math.h>
#include <algorithm>
#include <sstream>

using namespace std;


/*********************************************************************************************
剑指offer：1
//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数

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
剑指offer：2
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

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
剑指offer：3
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

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
剑指offer：4
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{ 1, 2, 4, 7, 3, 5, 6, 8 }和中序遍历序列{ 4, 7, 2, 1, 5, 3, 8, 6 }，
则重建二叉树并返回
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
剑指offer：5
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
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
剑指offer：6
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
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
剑指offer：7
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
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
剑指offer：7
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
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
剑指offer：8
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
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
剑指offer：9
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
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
剑指offer：10
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
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
剑指offer：10
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*********************************************************************************************/
class Solution {
public:
	double Power(double base, int exponent) {
		return pow(base, exponent);
	}
};

/*********************************************************************************************
剑指offer：11
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
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
剑指offer：12
输入一个链表，输出该链表中倒数第k个结点
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
剑指offer：13
输入一个链表，反转链表后，输出新链表的表头。
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
剑指offer：14
输入一个链表，反转链表后，输出新链表的表头。
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
剑指offer：15
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
剑指offer：16
操作给定的二叉树，将其变换为源二叉树的镜像。
二叉树的镜像定义：源二叉树
	 8
   /  \
  6   10
 / \  / \
5  7 9  11
镜像二叉树
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
剑指offer：17
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
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
剑指offer：18
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
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
剑指offer：19
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
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
剑指offer：20
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
剑指offer：21
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
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
剑指offer：22
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
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
剑指offer：23
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
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
剑指offer：24
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
剑指offer：25
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
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
剑指offer：26
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
超过数组长度的一半，因此输出2。如果不存在则输出0。
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
剑指offer：27
输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
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
剑指offer：28
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
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
剑指offer：29
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
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
剑指offer：30
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
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
剑指offer：31
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
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
剑指offer：32
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）
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
剑指offer：33
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 
即输出P%1000000007
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
剑指offer：34
输入两个链表，找出它们的第一个公共结点。
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
剑指offer：35
统计一个数字在排序数组中出现的次数。
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
剑指offer：38
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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
剑指offer：39
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
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
剑指offer：40
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
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
剑指offer：41
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? 
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
剑指offer：42
输入一个递增排序的数组和一个数字S，在数组中查找两个数，
使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。
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
剑指offer：43
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
是不是很简单？OK，搞定它！
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
剑指offer：44
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。
后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
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

	//字符串分割函数
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
剑指offer：45
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....
LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 
现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。
为了方便起见,你可以认为大小王是0。
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
剑指offer：46
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。
然后,他随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,
并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,
可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
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
剑指offer：47
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
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
剑指offer：48
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
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
剑指offer：49
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
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
剑指offer：50
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
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
剑指offer：51
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。
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
剑指offer：52
请实现一个函数用来匹配包括'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
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
剑指offer：53
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
PS:JAVA写更简单！！！！！直接两次转换，加转换失败的异常！
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
剑指offer：54
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
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
剑指offer：55
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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
剑指offer：56
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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