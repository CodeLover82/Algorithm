[ 플로이드-워셜 알고리즘 ]
그래프의 모든 정점에서 모든 정점으로 가는 최단거리, 그 최소 비용을 구하는 알고리즘.
O(N^3)

우선 모든 경로의 거리를 최댓값으로 설정한다. (자기자신으로 가는 것은 
k : 중간에 거치는 노드

#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

int n;
int dist[105][105];

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)for(int j = 1;j <= n;j++){
		if(i == j)continue;
		dist[i][j] = INF;
	}
	
	int m; cin >> m;
	while(m--){
		int a, b, c; cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(dist[i][j] == INF)cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}
