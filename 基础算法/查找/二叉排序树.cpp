#include <iostream>
using namespace std;

template<class T>
class NodeSBT // Ѕбµг
{
public:
	T data;
	NodeSBT<T> *lch;
	NodeSBT<T> *rch;
	NodeSBT() :lch(NULL), rch(NULL) {};  // іЙФ±іхКј»ЇБР±нЈ¬№№ФмК±єтѕНіхКј»Ї
};


/************************************************************************/
/* ІйХТ                                                                     */
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
/* ІеИл                                                                     */
/************************************************************************/
template<class T>
void InsertSBT(NodeSBT<T> *&R, T key)  // ЧўТвХвАпИЎБЛ*&!!!!!Ј¬І»И»І»їЙТФіЙ№¦
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
/* µЭ№йКЅІйХТґэЙѕіэЅбµг                                                   */
/************************************************************************/
template<class T>
bool DeleteSBT(NodeSBT<T> *&R, T key)
{
	if (R == NULL)	return false;
	else{
		if (key == R->data)	Delete(R); // Йѕіэµ±З°
		else if (key < R->data)	DeleteSBT(R->lch, key);
		else DeleteSBT(R->rch, key);
	}
	return true;
}
/************************************************************************/
/* ЙѕіэДіёцЅбµг
/* ЛјПлЈєУГЧуєўЧУ»тЧуєўЧУµДУТєўЧУґъМжЧФјє / УГУТєўЧУ»тУТєўЧУµДЧуєўЧУґъМжЧФјє
/************************************************************************/
template<class T>
void Delete(NodeSBT<T> *&R)
{
	cout << "ЙѕіэЅбµг" << R->data << "..." << endl;
	NodeSBT<T> *q, *s;
	if (R->lch == NULL){ // ЧуЅбµгОЄїХ
		q = R;
		R = R->rch;
		delete q;
	}
	else if (R->rch == NULL){ // УТЅЪµгОЄїХ
		q = R;
		R = R->lch;
		delete q;
	}
	else{
		q = R;
		s = R->lch; // ЧуєўЧУ
		while (s->rch != NULL){ // ХТµЅЧуєўЧУµДЧоУТєўЧУ
			q = s;
			s = s->rch;
		}
		R->data = s->data;
		if (R == q)	R->lch = s->lch; // Из№ыКЗ°СЧуєўЧУМж»»БЛ
		else q->rch = s->lch; // °СЧуєўЧУµДУТєўЧУМж»»БЛ
		delete s;
	}
}
/************************************************************************/
/* ЅЁБўЕЕРтКч                                                            */
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
/* ґтУЎЕЕРтКч                                                            */
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
	int a[7] = { 0, 2, 3, 5, 5, 9, 19 }; // ґУ0їЄКј
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