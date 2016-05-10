#include <iostream>
//#include <stdlib.h>
using namespace std;
#define maxn 1000+10 // ����������

struct rectangle{ // �洢����ĳ��Ϳ�Ľṹ��
	int length;
	int width;
};

int G[maxn][maxn]; // DAGͼ�ľ����ʾ
int d[maxn], n; // d[i] ����i���·��
rectangle rec[maxn]; // n������ṹ��

// ����ͼ
void createGraph()
{
	memset(G, 0, sizeof(G));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (rec[i].length>rec[j].length && rec[i].width>rec[j].width)
				G[i][j] = 1;
		}
	}
}

// ���仯��������
int dp(int i)
{
	int& ans = d[i]; // �������ã��򻯶���Ķ�д����
	if (ans > 0) return ans;
	ans = 1;
	for (int j = 0; j < n; j++){
		if (G[i][j]){ // i���԰�����j��
			int tmp = dp(j);
			ans = ans>tmp + 1 ? ans : tmp + 1;
		}
	}
	return ans;
}

int main()
{
	int N; // N���������
	cin >> N;
	while (N-- > 0){
		int ans = 0;
		cin >> n; // ���θ���
		// �洢���󳤿�
		for (int i = 0; i < n; i++){
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			rec[i].length = tmp1>tmp2 ? tmp1 : tmp2;
			rec[i].width = tmp1 <= tmp2 ? tmp1 : tmp2;
		}

		// ����ͼ
		createGraph();

		// ��ʼ����������
		memset(d, 0, sizeof(d));
		for (int i = 0; i < n; i++){
			int tmp = dp(i);
			ans = ans>tmp ? ans : tmp;
		}
		cout << ans << endl;
	}
	//system("pause");
	return 0;
}