[ 동적 계획법 ]

부분 문제는 한번만 계산하고 계산 결과를 재활용 함으로써 속도의 향상을 꾀한다.
그러기 위해서 각 문제의 답을 메모리에 저장해 둘 필요가 있다.

메모이제이션 : 함수의 결과를 저장하는 장소를 마련해 두고, 한 번 계산한 값을 저장해뒀다가 재활용하는 최적화 기법.
메모이제이션의 조건 : 참조적 투명성 = 함수의 반환값이 그 입력 값만으로 결정되는지의 여부. = 입력이 고정되어 있을 때, 그 결과가 항상 같아야 함.

메모이제이션의 구현 패턴 
0. 먼저 논리적인 실질적 코드(답 계산)를 구상하고, 그 다음에 기저사례를 생각.
   꼭 필요한 요소만 캐시로 저장한다. 생각해 봤을 때, 굳이 필요 없는 항목은
   즉시 메모이제이션 대상에서 제외.	
1. 항상 기저 사례를 제일 먼저 처리. 입력의 범위를 벗어난 경우 등
2. 함수의 반환 값이 항상 0 이상이라는 점을 이용해 캐시를 모두 -1로 초기화.
   값이 -1이라면 아직 계산되지 않은 값이다.
   그러나 만약 함수의 반환 값이 음수일 수도 있다면 다른 방법 사용
3. int &ret = cache[a][b] 처럼 참조형을 사용. 실수 가능성 줄인다.

ex )
int cache[2500][2500];

int func(int a, int b){
	if(...) return ...;
	
	int &ret = cache[a][b];
	if(ret != -1)return ret;
	
	// 답 계산
	
	return ret;
}

< DP + 경로 추적의 경우 >

1. 최적해를 만들었던 코드를 사용.
2. 별도의 경로추적 배열을 만들어서 거기다 따로 저장하는 코드 삽입.