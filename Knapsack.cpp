[ 배낭 문제 ]

dp[i][j] : i개까지 써서 무게를 k로 만들 때 얻을 수 있는 최대 가치.  
1. n을 안 쓰는 경우 : dp[i - 1][j]
2. n을 쓰는 경우 : dp[i - 1][j - weight[i]] + worth[i] (j >= weight[i] 일 때)


#include <iostream>
#include <algorithm>
using namespace std;

int dp[105][100005];
int weight[105], worth[105];
int n, k;

int main(){
	cin >> n >> k;
	
	for(int i = 1;i <= n;i++)cin >> weight[i] >> worth[i];
	
	for(int i = 1;i <= n;i++)for(int j = 0;j <= k;j++){
		int ret = dp[i - 1][j];
		if(j >= weight[i])ret = max(ret, dp[i - 1][j - weight[i]] + worth[i]);
		dp[i][j] = ret;
	}
	
	int ret = 0;
	for(int i = 0;i <= k;i++)ret = max(ret, dp[n][i]);
	
	cout << ret;
}
