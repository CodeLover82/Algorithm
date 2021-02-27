[ 가장 긴 증가하는 부분 수열 ]
인덱스는 1부터 시작한다.
v[0] 에는 존재할 수 없는 최솟값이 들어가며, dp[0]에는 문제의 (LIS + 1)이 들어간다. v[0]도 포함되기 때문이다.
즉, dp[0]에는 (전체 답 + 1)이 존재.
  
dp[i] : v[i]를 포함하고 여기서부터 맨 끝까지의 LIS

#include <iostream>
using namespace std;

int v[1005], dp[1005];
int n;

int func(int i){
	int &ret = dp[i];
	
	if(ret != -1)return ret;
	
	ret = 1;
	for(int j = i + 1;j <= n;j++){
		if(v[j] > v[i] && ret < 1 + func(j)){
		  ret = 1 + func(j);
		}
	}

	return ret;
}

int main(){
	cin >> n;
	
	v[0] = -1;
	for(int i = 1;i <= n;i++)cin >> v[i];
	for(int i = 0;i <= n;i++)dp[i] = -1;
	
	cout << func(0) - 1;
}


[ 각 숫자 추적하기 ]
각 위치에서 최댓값으로 가는 다음 위치를 기록해두어서 추적할 수 있게 한다.
https://www.acmicpc.net/problem/14002

#include <iostream>
using namespace std;

int v[1005], dp[1005], nex[1005];
int n;

int func(int i){
	int &ret = dp[i];
	
	if(ret != -1)return ret;
	
	ret = 1;
	for(int j = i + 1;j <= n;j++){
		if(v[j] > v[i] && ret < 1 + func(j)){
		  ret = 1 + func(j);
			nex[i] = j;
		}
	}

	return ret;
}

int main(){
	cin >> n;
	
	v[0] = -1;
	for(int i = 1;i <= n;i++)cin >> v[i];
	for(int i = 0;i <= n;i++)dp[i] = -1, nex[i] = -1;
	
	cout << func(0) - 1 << endl;
	
	int i = 0;
	while(nex[i] != -1){
		cout << v[nex[i]] <<" ";
		i = nex[i];
	}
}
  
