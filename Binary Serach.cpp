[ 이분 탐색 ]

주로 답의 최솟값과 최댓값을 알고있을 경우에 사용한다.

조건  : 오름차순 정렬.
	
< lower_bound >
: v[i - 1] < x <= v[i]인 i를 반환. 
배열 내에 x 값이 존재 할 때 : i개 여러개일 경우, 그 중 제일 앞의 인덱스 반환.
배열 내에 x 값이 존재하지 않을 때 : x보다 큰 첫 번째 인덱스 반환.

int Lower_Bound(int x){
	int s = 0, e = n; // e = n 으로 설정한 이유 : 배열의 제일 큰 숫자보다 클 경우 마지막 인덱스 + 1을 반환해야 하므로
	
	while(s < e){
		int mid = (s + e) / 2;
		
		if(v[mid] < x)s = mid + 1; // upper_bound와 이부분만 다름. 
		else e = mid;
	}
	return s;
}

< upper_bound >
	
: v[i - 1] <= x < v[i]인 i를 반환. 
배열 내에 x 값이 존재 할 때 & 존재하지 않을 때: x보다 큰 첫 번째 인덱스 반환.
	
int Upper_Bound(int x){
	int s = 0, e = n; 
	
	while(s < e){
		int mid = (s + e) / 2;
		
		if(v[mid] <= x)s = mid + 1;
		else e = mid;
	}
	return s;
}

< 실수형일 때 >

double Binary(){
	double s = 0, e = n; 
	
	for(int iter = 0;iter < 100;iter++){ // 구체적인 제한 조건없이 100번 정도만 반복한다면 2^(-100)만큼 (= 10^(-31))로 웬만한 오차범위까지는 줄일 수 있다. 
										 // 더 정확도를 높이고자 한다면 반복문의 횟수를 증가시키면 될 것이다.
		double mid = (s + e) / 2;
		
		if(f())s = mid; // 점차 정확도를 개선하는 방식으로 함.
		else e = mid;
	}
	
	return s;
}

< 사용법 >

int main(){
	cin >> n;
	for(int i = 0;i < n;i++)cin >> v[i];
	sort(v,v + n);
	
	int x; cin >> x;
	int ret = Lower_Bound(x);
	
	// 배열 내에 x가 존재한다면 v[ret] = x
	// 존재하지 않는다면 v[ret] > x인 가장 작은 인덱스 반환.
}

+ 찾는 값이 여러개 일 때 그 개수 찾는 법
upperbound - lowerbound
 																									   //     x값이 존재하지 않을 때 : x 보다 큰 첫번째 위치를 반환 
