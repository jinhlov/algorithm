#include <iostream>
using namespace std;

bool PostSequenceOfBST(int a[], int length)
{
	if (a == NULL || length <= 0) // 数组有效性验证
		return false;
	int root = a[length - 1]; // 根节点
	int i = 0;
	for (; i < length - 1; i++){ // 搜索左子树的节点
		if (a[i] > root) // i为左子树长度
			break;
	}
	int j = i; // 搜索右子树的节点
	for (; j < length - 1; j++){
		if (a[j] < root)  // 右子树上发现小于根的值返回false
			return false;
	}
	bool left = true;
	if (i>0) // 左子树存在
		left = PostSequenceOfBST(a, i);
	bool right = true;
	if (i < length - 1) // 右子树存在
		right = PostSequenceOfBST(a + i, length - i - 1);
	return (left&&right);

}

int main(){
	cout << "请输入数组：" << endl;
	int s[7];
	for (int i = 0; i < 7; i++)
		cin >> s[i];
	bool result = PostSequenceOfBST(s, 6);
	if (result)
		cout << "该数组是二叉查找树的后序遍历" << endl;
	else
		cout << "该数组不是二叉查找树的后序遍历" << endl;
	return 0;
}