#include <iostream>
using namespace std;

/*******��������O(n2)*********/
void insertSort(int D[], int length)
{
	int key;
	for (int i = 1; i < length; i++){
		key = D[i]; // ��Ҫ��ǰ�����Ԫ��
		int j = i - 1;
		while (j >= 0 && D[j] > key) {
			D[j + 1] = D[j]; // ��С���������ƶ�
			j--; // ��ǰ�ƶ������Ƚ�
		}
		D[j + 1] = key; // ��������Ԫ�ز���j+1��λ�ã���Ϊj����Ԫ�ر�keyС
	}
}

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/*
bubbleSort(D)
�³�����
i = n-1; flag = 1
while i>0 and flag=1
do flag = 0
for j <- 0 to i-1
if D[j]>D[j+1]
swap(D[j], D[j+1]
flag = 1
i--
*/
/*******ð������O(n2)*********/
void bubbleSort(int D[], int length)
{
	int i = length - 1, flag = 1;
	while (i > 0 && flag == 1) { // ������˵�һλ������������������һ��û�з������������˳�whileѭ��
		flag = 0;
		for (int j = 0; j < i; j++) {
			if (D[j]>D[j + 1]) {
				swap(D[j], D[j + 1]);
				flag = 1; // ������
			}
		}
		i--;
	}
}
/***********��������***********/
int partion(int D[], int p, int r)
{
	int pivot = D[p];
	while (p < r){
		while ((D[r] >= pivot) && (p < r)) // �Ҳ�ɨ�裬����С����ֵ��Ԫ��
			r--;
		D[p] = D[r]; // ����
		while ((D[p] <= pivot) && (p < r)) // ���ɨ�裬���Ҵ�����ֵ��Ԫ��
			p++;
		D[r] = D[p]; // ����
	}
	D[p] = pivot;
	return p;
}

void quickSort(int D[], int p, int r)
{
	int position = 0;
	if (p < r) {
		position = partion(D, p, r);
		quickSort(D, p, position - 1);
		quickSort(D, position + 1, r);
	}
}

/**************�鲢����****************/
void merge(int D[], int start, int mid, int end)
{
	int n1 = mid - start + 1;
	int n2 = end - mid;
	int* left = new int[n1];
	int* right = new int[n2];

	// ���浽��������
	for (int i = 0; i < n1; i++)
		left[i] = D[start + i];
	for (int i = 0; i < n2; i++)
		right[i] = D[mid + 1 + i];

	int i = 0, j = 0, k = start;
	while (i < n1 && j < n2)
	{
		if (left[i] < right[j])
			D[k++] = left[i++];
		else
			D[k++] = right[j++];
	}
	while (i < n1) // ���ʣ�µ�
		D[k++] = left[i++];
	while (j < n2) // �ұ�ʣ�µ�
		D[k++] = right[j++];

	delete left;
	delete right;
}

void mergeSort(int D[], int start, int end)
{
	int mid;
	if (start < end){
		mid = (start + end) / 2;
		mergeSort(D, start, mid);
		mergeSort(D, mid + 1, end);
		merge(D, start, mid, end);
	}
}





void main()
{
	int a[6] = { 3, 2, 15, 5, 19, 3 };
	int length = 6;
	mergeSort(a, 0, length - 1);
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	getchar();
	getchar();
}