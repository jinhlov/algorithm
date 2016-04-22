#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Sift(int data[], int k, int m) // ��k��m��һ�Σ���Ҫ����
{
	int i = k, j = 2 * i; // i��Ҫɸѡ�Ľڵ㣬j��i������
	while (j <= m) {
		if (j<m && data[j]>data[j + 1]) // ��j���ڱȽ�С�Ľڵ��λ��
			j++;
		if (data[i] < data[j]) // ����С��������
			break;
		else{ // ���򽻻��ڵ�ֵ�����Ҽ����Խ�������Ӷѽ��е���
			swap(data[i], data[j]);
			i = j;
			j = 2 * i;
		}
	}
}

void HeapSort(int data[], int n)
{
	// ���ѣ��ӵ����϶����и��ڵ���е���
	for (int i = n / 2; i >= 1; i--)
		Sift(data, i, n);

	for (int i = 1; i < n; i++){
		// ����Ѷ�Ԫ��
		swap(data[1], data[n - i + 1]);
		Sift(data, 1, n - i);
	}
}

void main()
{
	int a[7] = { 0, 3, 2, 15, 5, 19, 3 };
	int length = 6;
	HeapSort(a, length);
	// ����С���ѣ���Ҫ�������
	for (int i = length; i > 0; i--)
		cout << a[i] << " ";
	getchar();
	getchar();
}