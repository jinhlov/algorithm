// ������ļ��
// ˢ��
#include <iostream>
using namespace std;

#define MAXN 50 + 10 //  ��վ��
#define INF 9999999

int n, T, M1, M2;
int t[MAXN], d1[MAXN], d2[MAXN];// t-������i��i+1ʱ�� d1-���ҿ�ʱ��
int has_train[MAXN][MAXN][2];
int dp[MAXN][MAXN];

int min(int a, int b){
	return a < b ? a : b;
}

int main() {
	cin >> n; // ��վ��
	cin >> T; // ʱ��T

	t[0] = 0;
	for (int i = 1; i <= n - 1; i++)
		cin >> t[i]; // ��ʻʱ�䣬��i��i+1

	memset(has_train, 0, sizeof(has_train));

	cin >> M1; // �����ҳ���
	for (int i = 1; i <= M1; i++) {
		cin >> d1[i]; // ����ʱ��
		int sum = d1[i];
		for (int j = 1; j <= n; j++)
		{
			sum += t[j - 1]; // ����t[j-1]��j-1����j��վ
			has_train[sum][j][0] = 1;
		}
	}

	cin >> M2; // ��������
	for (int i = 1; i <= M2; i++) {
		cin >> d2[i]; // ����ʱ��
		int sum = d2[i];
		for (int j = 1; j <= n; j++)
		{
			sum += t[j - 1]; // ����t[j-1]��j-1����j��վ
			has_train[sum][j][1] = 1;
		}
	}

	// �߽�������ʱ��T
	for (int i = 1; i <= n - 1; i++)
		dp[T][i] = INF;
	dp[T][n] = 0;

	for (int i = T - 1; i >= 0; i--) { // T-1ʱ�̵�0ʱ��
		for (int j = 1; j <= n; j++) { // 1��վ��n��վ
			dp[i][j] = dp[i + 1][j] + 1; // ��һ����
			if (j < n && has_train[i][j][0] && i + t[j] <= T)
				dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]); // ��������������
			if (j > 1 && has_train[i][j][1] && i + t[j - 1] <= T)
				dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]); // ��������������
		}
	}

	if (dp[0][1] >= INF)
		cout << "Impossible" << endl;
	else
		cout << dp[0][1] << endl;
	getchar();
	getchar();
}