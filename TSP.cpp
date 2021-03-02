[ 외판원 순회 ]
dp[i][j] : 현재 위치가 i이고 방문한 위치의 비트마스크가 j일 때, 현재 위치부터 남은 도시를 다 돌고 다시 시작점으로 복귀할 때 까지의 최소 비용.
	
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 2000000000;

int n;
int dp[20][1 << 20];
int cost[20][20];

int TSP(int now, int visited){
	if(visited == (1 << n) - 1)return dp[now][visited] = (cost[now][0] == 0 ? INF : cost[now][0]);
	
	int &ret = dp[now][visited];
	if(ret != -1)return ret;
	
	ret = INF;
	for(int next = 0;next < n;next++){
		if((1 << next) & visited)continue;
		if(cost[now][next] == 0)continue;
		
		ret = min(ret, cost[now][next] + TSP(next, visited + (1 << next)));
	}
	
	return ret;  
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++)for(int j = 0;j < n;j++)cin >> cost[i][j];
	for(int i = 0;i < n;i++)for(int j = 0;j < (1 << n);j++)dp[i][j] = -1;
	cout << TSP(0, 1);
}
