#include <iostream>
using namespace std;

// 找出最小的，放在最前面
void selectsort(int data[], int n)
{
	int temp;
	for (int i = 0; i < n; i++){
		int minIndex = i; // 初始最小数index
		for (int j = i + 1; j < n; j++){ // 从i开始到n-1寻找最小值
			if (data[j] < data[minIndex]) {
				minIndex = j; // 获得当前最小值
			}
		}
		// 找到最小值的位置，和i位置的数交换（之后从i+1位置继续往后找）
		temp = data[minIndex];
		data[minIndex] = data[i];
		data[i] = temp;
	}
}

void main()
{
	int a[6] = { 3, 2, 15, 5, 19, 3 };
	int length = 6;
	selectsort(a, length);
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	getchar();
	getchar();
}