
[ BFS ]

루트 노드에서 시작해서 인접한 노드를 먼저 탐색하는 방법.

시작 정점으로부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 순회 방법이다.
즉, 깊게(deep) 탐색하기 전에 넓게(wide) 탐색하는 것이다.
	
두 노드 사이의 최단 경로 혹은 임의의 경로를 찾고 싶을 때 이 방법을 선택한다.


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1000;

vector<int> adj[MAX + 1];
bool visited[MAX + 1];

int main(){
  int n, m, s; // n은 정점의 개수, m은 간선의 개수, s는 root 노드.
	cin >> n >> m >> s;
	
	for(int i = 0;i < m;i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i = 1;i <= n;i++)sort(adj[i].begin(), adj[i].end());
	
	queue<int> q;
	
	q.push(s);
	visited[s] = true;
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		cout << now << " ";
		for(int i = 0;i < adj[now].size();i++){
			int next = adj[now][i];
			
			if(visited[next])continue;
			
			q.push(next);
			visited[next] = true;
		}
	}
}
