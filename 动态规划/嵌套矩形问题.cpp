#include <iostream>
//#include <stdlib.h>
using namespace std;
#define maxn 1000+10 // 矩阵最多个数

struct rectangle{ // 存储矩阵的长和宽的结构体
	int length;
	int width;
};

int G[maxn][maxn]; // DAG图的矩阵表示
int d[maxn], n; // d[i] 顶点i的最长路径
rectangle rec[maxn]; // n个矩阵结构体

// 构造图
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

// 记忆化搜索程序
int dp(int i)
{
	int& ans = d[i]; // 声明引用，简化对其的读写操作
	if (ans > 0) return ans;
	ans = 1;
	for (int j = 0; j < n; j++){
		if (G[i][j]){ // i可以包含在j里
			int tmp = dp(j);
			ans = ans>tmp + 1 ? ans : tmp + 1;
		}
	}
	return ans;
}

int main()
{
	int N; // N组测试用例
	cin >> N;
	while (N-- > 0){
		int ans = 0;
		cin >> n; // 矩形个数
		// 存储矩阵长宽
		for (int i = 0; i < n; i++){
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			rec[i].length = tmp1>tmp2 ? tmp1 : tmp2;
			rec[i].width = tmp1 <= tmp2 ? tmp1 : tmp2;
		}

		// 建立图
		createGraph();

		// 初始化记忆数组
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