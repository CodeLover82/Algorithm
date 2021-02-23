#include <algorithm>

[ 정렬 ]

< 오름차순 >
sort(v.begin(), v.end()); 

< 내림차순 > 
bool cmp(int i, int j){
	return i > j;
}
sort(v.begin(), v.end(), cmp);

< 임의의 방법으로 정렬 >
정렬함수를 만든다. 위의 cmp 함수가 예시이다.
sort의 세 번째 인자에 해당 함수를 넣는다.










