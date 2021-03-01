[ 다익스트라 알고리즘 ]
그래프의 한 정점에서 모든 정점까지의 최단 거리를 구하는 알고리즘.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1000000000;

int n, s;
int dp[20005];
vector<pair<int, int>> adj[20005]; // (다음 노드, 거리)
priority_queue<pair<int, int>> pq; // (-총 거리, 다음 노드)

int main(){
	int m; cin >> n >> m >> s;
	while(m--){
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b, c});	
	}
	
	for(int i = 1;i <= n;i++)dp[i] = INF;
	dp[s] = 0;
	
	
	pq.push({0, s});
	while(!pq.empty()){
		int now = pq.top().second;
		int total = -pq.top().first;
		pq.pop();
		
		if(dp[now] < total)continue;
		
		for(int i = 0;i < adj[now].size();i++){
			int next = adj[now][i].first;
			int add = adj[now][i].second;
			
			if(dp[next] > total + add){
				dp[next] = total + add;
				pq.push({-dp[next], next});
			}
				
		}
	}
	
	for(int i = 1;i <= n;i++){
		if(dp[i] == INF)cout << "INF" << endl;
		else cout << dp[i] << endl;
	}
	
}
