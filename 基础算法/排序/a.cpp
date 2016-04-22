#include <iostream>
using namespace std;

/*******插入排序，O(n2)*********/
void insertSort(int D[], int length)
{
	int key;
	for (int i = 1; i < length; i++){
		key = D[i]; // 需要往前插入的元素
		int j = i - 1;
		while (j >= 0 && D[j] > key) {
			D[j + 1] = D[j]; // 较小的数往后移动
			j--; // 往前移动继续比较
		}
		D[j + 1] = key; // 将待插入元素插入j+1的位置，因为j处的元素比key小
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
下沉排序
i = n-1; flag = 1
while i>0 and flag=1
do flag = 0
for j <- 0 to i-1
if D[j]>D[j+1]
swap(D[j], D[j+1]
flag = 1
i--
*/
/*******冒泡排序，O(n2)*********/
void bubbleSort(int D[], int length)
{
	int i = length - 1, flag = 1;
	while (i > 0 && flag == 1) { // 如果除了第一位后面的数都有序或者上一次没有发生交换，则退出while循环
		flag = 0;
		for (int j = 0; j < i; j++) {
			if (D[j]>D[j + 1]) {
				swap(D[j], D[j + 1]);
				flag = 1; // 交换过
			}
		}
		i--;
	}
}
/***********快速排序***********/
int partion(int D[], int p, int r)
{
	int pivot = D[p];
	while (p < r){
		while ((D[r] >= pivot) && (p < r)) // 右侧扫描，查找小于轴值的元素
			r--;
		D[p] = D[r]; // 交换
		while ((D[p] <= pivot) && (p < r)) // 左侧扫描，查找大于轴值的元素
			p++;
		D[r] = D[p]; // 交换
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

/**************归并排序****************/
void merge(int D[], int start, int mid, int end)
{
	int n1 = mid - start + 1;
	int n2 = end - mid;
	int* left = new int[n1];
	int* right = new int[n2];

	// 保存到新数组里
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
	while (i < n1) // 左边剩下的
		D[k++] = left[i++];
	while (j < n2) // 右边剩下的
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