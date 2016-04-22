#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Sift(int data[], int k, int m) // 从k到m这一段，需要调整
{
	int i = k, j = 2 * i; // i是要筛选的节点，j是i的左孩子
	while (j <= m) {
		if (j<m && data[j]>data[j + 1]) // 令j等于比较小的节点的位置
			j++;
		if (data[i] < data[j]) // 符合小根堆条件
			break;
		else{ // 否则交换节点值，并且继续对交换后的子堆进行调整
			swap(data[i], data[j]);
			i = j;
			j = 2 * i;
		}
	}
}

void HeapSort(int data[], int n)
{
	// 建堆，从底往上对所有父节点进行调整
	for (int i = n / 2; i >= 1; i--)
		Sift(data, i, n);

	for (int i = 1; i < n; i++){
		// 输出堆顶元素
		swap(data[1], data[n - i + 1]);
		Sift(data, 1, n - i);
	}
}

void main()
{
	int a[7] = { 0, 3, 2, 15, 5, 19, 3 };
	int length = 6;
	HeapSort(a, length);
	// 建立小根堆，需要倒序输出
	for (int i = length; i > 0; i--)
		cout << a[i] << " ";
	getchar();
	getchar();
}