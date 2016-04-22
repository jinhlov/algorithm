#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void shellsort1(int a[], int n)  // �Ƚ��鷳��δ�Ż�
{
	int i, j, gap;

	for (gap = n / 2; gap > 0; gap /= 2) //����
	for (i = 0; i < gap; i++)        //ֱ�Ӳ�������
	{
		for (j = i + gap; j < n; j += gap)
		if (a[j] < a[j - gap])
		{
			int temp = a[j];
			int k = j - gap;
			while (k >= 0 && a[k] > temp)
			{
				a[k + gap] = a[k];
				k -= gap;
			}
			a[k + gap] = temp;
		}
	}
}

void shellsort(int data[], int n)
{
	int i, j, gap;
	int flag = 1; // 0Ϊδ����
	for (gap = n / 2; gap > 0; gap /= 2){
		flag = 0;
		for (i = gap; i < n; i++)
		for (j = i - gap; j >= 0 && data[j] > data[j + gap]; j -= gap){
			swap(data[j], data[j + gap]);
			flag = 1;
		}

	}
}


void main()
{
	int a[6] = { 3, 2, 15, 5, 19, 3 };
	int length = 6;
	shellsort(a, length);
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	/*	getchar();
	getchar();*/
}