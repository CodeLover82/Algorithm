[ DFS ]
루트 노드에서 시작해서 다음 가지로 넘어가기 전에 해당 가지를 완벽하게 탐색하는 방법.

미로를 탐색할 때 한 방향으로 갈 수 있을 때까지 계속 가다가 더 이상 갈 수 없게 되면 다시 가장 가까운 갈림길로 돌아와서 이곳으로부터 다른 방향으로 다시 탐색을 진행하는 방법과 유사하다.
즉, 넓게(wide) 탐색하기 전에 깊게(deep) 탐색하는 것이다.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1000;

vector<int> adj[MAX + 1];
bool visited[MAX + 1];

void dfs(int now){
	cout << now << " ";
	
	for(int i = 0;i < adj[now].size();i++){
		int next = adj[now][i];

		if(visited[next])continue;

		visited[next] = true;
		dfs(next);
	}
}

int main(){
	int n, m, s; // n은 정점의 개수, m은 간선의 개수, s는 root 노드.
	cin >> n >> m >> s;
	
	for(int i = 0;i < m;i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i = 1;i <= n;i++)sort(adj[i].begin(), adj[i].end());
	
	visited[s] = true;
	dfs(s);
}
