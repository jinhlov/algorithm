// 城市里的间谍
// 刷表法
#include <iostream>
using namespace std;

#define MAXN 50 + 10 //  车站数
#define INF 9999999

int n, T, M1, M2;
int t[MAXN], d1[MAXN], d2[MAXN];// t-地铁从i到i+1时间 d1-往右开时刻
int has_train[MAXN][MAXN][2];
int dp[MAXN][MAXN];

int min(int a, int b){
	return a < b ? a : b;
}

int main() {
	cin >> n; // 车站数
	cin >> T; // 时刻T

	t[0] = 0;
	for (int i = 1; i <= n - 1; i++)
		cin >> t[i]; // 行驶时间，从i到i+1

	memset(has_train, 0, sizeof(has_train));

	cin >> M1; // 左往右车数
	for (int i = 1; i <= M1; i++) {
		cin >> d1[i]; // 出发时间
		int sum = d1[i];
		for (int j = 1; j <= n; j++)
		{
			sum += t[j - 1]; // 花费t[j-1]从j-1到达j车站
			has_train[sum][j][0] = 1;
		}
	}

	cin >> M2; // 右往左车数
	for (int i = 1; i <= M2; i++) {
		cin >> d2[i]; // 出发时间
		int sum = d2[i];
		for (int j = 1; j <= n; j++)
		{
			sum += t[j - 1]; // 花费t[j-1]从j-1到达j车站
			has_train[sum][j][1] = 1;
		}
	}

	// 边界条件，时间T
	for (int i = 1; i <= n - 1; i++)
		dp[T][i] = INF;
	dp[T][n] = 0;

	for (int i = T - 1; i >= 0; i--) { // T-1时刻到0时刻
		for (int j = 1; j <= n; j++) { // 1车站到n车站
			dp[i][j] = dp[i + 1][j] + 1; // 等一分钟
			if (j < n && has_train[i][j][0] && i + t[j] <= T)
				dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]); // 坐车还是往右走
			if (j > 1 && has_train[i][j][1] && i + t[j - 1] <= T)
				dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]); // 坐车还是往左走
		}
	}

	if (dp[0][1] >= INF)
		cout << "Impossible" << endl;
	else
		cout << dp[0][1] << endl;
	getchar();
	getchar();
}