#include <iostream>
using namespace std;

// �ҳ���С�ģ�������ǰ��
void selectsort(int data[], int n)
{
	int temp;
	for (int i = 0; i < n; i++){
		int minIndex = i; // ��ʼ��С��index
		for (int j = i + 1; j < n; j++){ // ��i��ʼ��n-1Ѱ����Сֵ
			if (data[j] < data[minIndex]) {
				minIndex = j; // ��õ�ǰ��Сֵ
			}
		}
		// �ҵ���Сֵ��λ�ã���iλ�õ���������֮���i+1λ�ü��������ң�
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