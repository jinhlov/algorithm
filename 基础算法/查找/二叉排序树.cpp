#include <iostream>
using namespace std;

template<class T>
class NodeSBT // 结点
{
public:
	T data;
	NodeSBT<T> *lch;
	NodeSBT<T> *rch;
	NodeSBT() :lch(NULL), rch(NULL) {};  // 成员初始化列表，构造时候就初始化
};


/************************************************************************/
/* 查找                                                                     */
/************************************************************************/
template<class T>
NodeSBT<T> *SearchSBT(NodeSBT<T> *R, T key)
{
	if (R == NULL)	return NULL;
	if (R->data == key)	return R;
	else if (R->data > key)	return SearchSBT(R->lch, key);
	else return SearchSBT(R->rch, key);
}

/************************************************************************/
/* 插入                                                                     */
/************************************************************************/
template<class T>
void InsertSBT(NodeSBT<T> *&R, T key)  // 注意这里取了*&!!!!!，不然不可以成功
{
	if (R == NULL){
		R = new NodeSBT<T>();
		R->data = key;
		return;
	}
	else if (R->data < key)
		InsertSBT(R->rch, key);
	else
		InsertSBT(R->lch, key);
}
/************************************************************************/
/* 递归式查找待删除结点                                                   */
/************************************************************************/
template<class T>
bool DeleteSBT(NodeSBT<T> *&R, T key)
{
	if (R == NULL)	return false;
	else{
		if (key == R->data)	Delete(R); // 删除当前
		else if (key < R->data)	DeleteSBT(R->lch, key);
		else DeleteSBT(R->rch, key);
	}
	return true;
}
/************************************************************************/
/* 删除某个结点
/* 思想：用左孩子或左孩子的右孩子代替自己 / 用右孩子或右孩子的左孩子代替自己
/************************************************************************/
template<class T>
void Delete(NodeSBT<T> *&R)
{
	cout << "删除结点" << R->data << "..." << endl;
	NodeSBT<T> *q, *s;
	if (R->lch == NULL){ // 左结点为空
		q = R;
		R = R->rch;
		delete q;
	}
	else if (R->rch == NULL){ // 右节点为空
		q = R;
		R = R->lch;
		delete q;
	}
	else{
		q = R;
		s = R->lch; // 左孩子
		while (s->rch != NULL){ // 找到左孩子的最右孩子
			q = s;
			s = s->rch;
		}
		R->data = s->data;
		if (R == q)	R->lch = s->lch; // 如果是把左孩子替换了
		else q->rch = s->lch; // 把左孩子的右孩子替换了
	}
}
/************************************************************************/
/* 建立排序树                                                            */
/************************************************************************/
template<class T>
void CreateSBT(NodeSBT<T> *R, int r[], int n)
{
	for (int i = 1; i < n; i++){
		/*		SBTNode<T> *node = new SBTNode<T>;
		node->data = r[i];*/
		InsertSBT(R, r[i]);
	}
}
/************************************************************************/
/* 打印排序树                                                            */
/************************************************************************/
template<class T>
void IteratorSBT(NodeSBT<T> *R)
{
	if (R == NULL)	return;
	IteratorSBT(R->lch);
	cout << R->data << " ";
	IteratorSBT(R->rch);
}

void main()
{
	int a[7] = { 0, 2, 3, 5, 5, 9, 19 }; // 从0开始
	int length = 7;
	NodeSBT<int> *root = new NodeSBT<int>;
	root->data = a[0];
	CreateSBT(root, a, length);
	IteratorSBT(root);
	cout << endl;
	DeleteSBT(root, 2);
	IteratorSBT(root);
	cout << endl;
}