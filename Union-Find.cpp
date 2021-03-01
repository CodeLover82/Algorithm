#include <iostream>
using namespace std;

int parent[1000005];

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
	for(int i = 0;i <= n;i++)parent[i] = i;
	
	while(m--){
		int cmd, a, b; cin >> cmd >> a >> b;
		if(cmd == 0){
			Union(a, b);
		}else{
			if(Find(a) == Find(b))cout <<"YES" << endl;
			else cout << "NO" << endl;
		}
	}
}
