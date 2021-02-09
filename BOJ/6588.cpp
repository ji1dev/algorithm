// 6588번_골드바흐의 추측
#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;

vector<bool> prime(MAX+1, true);

// 1929번_소수 구하기 문제 참고 (에라토스테네스의 체)
void init(){
    prime[1] = false;
    for(int i=2; i*i<=MAX; ++i){
        if(prime[i]){
            for(int j=i*2; j<=MAX; j+=i) prime[j] = false;
        }
    }
}
int main(){
    int n;
    init(); // 소수 구하기
    while(1){
        bool gb = false;
        scanf("%d", &n);
        if(n == 0) break;
        for(int i=3; i<=n; ++i){
            // n = a + b 에서 a, b 모두 소수인지 확인 (b = n-a)
            if(prime[i] && prime[n-i]){ 
                printf("%d = %d + %d\n", n, i, n-i);
                gb = true;
                break; // b-a 가 가장 큰 것은 처음 발견한 a, b 조합
            }
        }
        if(!gb){
            printf("Goldbach's conjecture is wrong.\n");
        }  
    }
    return 0;
}