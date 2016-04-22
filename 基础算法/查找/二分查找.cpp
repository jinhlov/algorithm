#include <iostream>
using namespace std;

/*********递归二分查找**********/
int binSearchRecursion(int a[], int low, int high, int key)
{
	if (low <= high){
		int mid = (low + high) / 2; // 中值点
		if (a[mid] == key)	return mid;
		else if (a[mid] > key)	return binSearchRecursion(a, low, mid - 1, key);
		else    return binSearchRecursion(a, mid + 1, high, key);
	}
	return 0;
}

/*********非递归二分查找**********/
int binSearch(int a[], int n, int key)
{
	int low = 1;
	int high = n;
	int mid;
	while (low <= high){
		mid = (low + high) / 2;
		if (a[mid] == key)	return mid;
		else if (a[mid] > key)	high = mid - 1;
		else    low = mid + 1;
	}
	return 0;
}

void main()
{
	int a[7] = { 0, 2, 3, 5, 5, 9, 19 };
	int length = 6;
	int k = binSearch(a, length, 2);
	cout << k;
}