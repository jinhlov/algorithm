#include <iostream>
using namespace std;

int seqSearch1(int a[], int n, int key)
{
	for (int i = 1; i <= n; i++){
		if (key == a[i])
			return key;
	}
	return 0;
}

/******改进的顺序查找，将第一个元素设成******/
int seqSearch2(int a[], int n, int key)
{
	a[0] = key; // 设置哨兵，从后往前比较
	int i = n;
	for (; key != a[i]; i--);
	return i;
}


void main()
{
	int a[7] = { 0, 3, 2, 15, 5, 19, 3 };
	int length = 6;
	int k = seqSearch2(a, length, 2);
	cout << k;
}