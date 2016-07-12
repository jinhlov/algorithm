#include <iostream>
using namespace std;

template<class T>
class NodeSBT // 节点类
{
public:
	T data;
	NodeSBT<T> *lch;
	NodeSBT<T> *rch;
	NodeSBT() :lch(NULL), rch(NULL) {};  // 成员初始化
};


/************************************************************************/
/* 查找                                                                  */
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
/* 插入                                                                  */
/************************************************************************/
template<class T>
void InsertSBT(NodeSBT<T> *&R, T key)  // 注意这里由于改变了*R指针本身的值，所以需要加&
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
/* 删除前查找                                                             */
/************************************************************************/
template<class T>
bool DeleteSBT(NodeSBT<T> *&R, T key)
{
	if (R == NULL)	return false;
	else{
		if (key == R->data)	Delete(R); // 删除节点
		else if (key < R->data)	DeleteSBT(R->lch, key);
		else DeleteSBT(R->rch, key);
	}
	return true;
}
/************************************************************************/
/* 删除
/************************************************************************/
template<class T>
void Delete(NodeSBT<T> *&R)
{
	cout << "删除节点" << R->data << "..." << endl;
	NodeSBT<T> *q, *s;
	if (R->lch == NULL){ // 如果右子树不存在
		q = R;
		R = R->rch;
		delete q;
	}
	else if (R->rch == NULL){ // 如果左子树不存在
		q = R;
		R = R->lch;
		delete q;
	}
	else{
		q = R; // s存放用来替换的节点，q存在其前驱节点
		s = R->lch; 
		while (s->rch != NULL){ // 一直向右遍历直到为空
			q = s;
			s = s->rch;
		}
		R->data = s->data;
		if (R == q)	R->lch = s->lch; // 如果R的左孩子s没有右孩子 
		else q->rch = s->lch; // 如果有
		delete s;
	}
}
/************************************************************************/
/* 创建一棵树                                                             */
/************************************************************************/
template<class T>
void CreateSBT(NodeSBT<T> *R, int r[], int n)
{
	for (int i = 1; i < n; i++){
		InsertSBT(R, r[i]);
	}
}
/************************************************************************/
/* 输出二叉树                                                             */
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
	int a[7] = { 0, 2, 3, 5, 6, 9, 19 };  
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