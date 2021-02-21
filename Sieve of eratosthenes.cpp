[ 에라토스테네스의 체 ]

소수판별 알고리즘.

const int MAX = 100001;
bool isPrime[MAX];

void getPrime(){
    for(int i = 2;i < MAX;i++)isPrime[i] = true;
    for(int i = 2;i < MAX;i++){
        if(isPrime[i] == false)continue;
        
        for(int j = i + i;j < MAX;j += i)isPrime[j] = false;
    }
}
