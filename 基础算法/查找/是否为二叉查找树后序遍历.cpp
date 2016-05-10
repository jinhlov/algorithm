#include <iostream>
using namespace std;

bool PostSequenceOfBST(int a[], int length)
{
	if (a == NULL || length <= 0) // ������Ч����֤
		return false;
	int root = a[length - 1]; // ���ڵ�
	int i = 0;
	for (; i < length - 1; i++){ // �����������Ľڵ�
		if (a[i] > root) // iΪ����������
			break;
	}
	int j = i; // �����������Ľڵ�
	for (; j < length - 1; j++){
		if (a[j] < root)  // �������Ϸ���С�ڸ���ֵ����false
			return false;
	}
	bool left = true;
	if (i>0) // ����������
		left = PostSequenceOfBST(a, i);
	bool right = true;
	if (i < length - 1) // ����������
		right = PostSequenceOfBST(a + i, length - i - 1);
	return (left&&right);

}

int main(){
	cout << "���������飺" << endl;
	int s[7];
	for (int i = 0; i < 7; i++)
		cin >> s[i];
	bool result = PostSequenceOfBST(s, 6);
	if (result)
		cout << "�������Ƕ���������ĺ������" << endl;
	else
		cout << "�����鲻�Ƕ���������ĺ������" << endl;
	return 0;
}