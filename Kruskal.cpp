[ 크루스칼 알고리즘]
MST를 만드는 알고리즘 중 하나로서,
그리디를 이용하여 네트워크의 모든 정점을 최소 비용으로 연결하는 최적 해답을 구하는 것.
  

#include <iostream>
#include <queue>
using namespace std;
struct edge{
	int s, e, cost;
};

bool operator<(edge a, edge b){
	return a.cost < b.cost;
}

int parent[10005];
priority_queue<edge> pq;

int Find(int x){
	if(parent[x] == x)return x;
	
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b){
	int x = Find(a);
	int y = Find(b);	
	
	if(x == y)return;
	
	if(x > y)parent[x] = y;
	else parent[y] = x;
}

int main(){
	int n, m; cin >> n >> m;
	int total = 0;
	
	for(int i = 1;i <= n;i++)parent[i] = i;
	
	while(m--){
		int a, b, c; cin >> a >> b >> c;
		pq.push({a, b, -c});
	}
	
	while(!pq.empty()){
		int a = pq.top().s;
		int b = pq.top().e;
		int cost = -pq.top().cost;
		pq.pop();
		
		if(Find(a) == Find(b))continue;
		Union(a, b);
		total += cost;
	}
	
	cout << total;
}
