// 1929번_소수 구하기
#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;
int main(){
    vector<bool> prime(MAX+1, true); prime[1] = false;
    int m, n;
    cin >> m >> n;

    // 에라토스테네스의 체 방법으로 소수가 아닌 수를 걸러냄
    // 1978번_소수 찾기 문제와 마찬가지로 2~n까지의 소수를 찾기위해
    // n의 제곱근 까지만 검사하면 됨 
    for(int i=2; i*i<=MAX; ++i){
        if(prime[i]){
            for(int j=i*2; j<=MAX; j+=i) prime[j] = false;
        }
    }

    for(int i=m; i<=n; ++i){
        if(prime[i]) cout << i << "\n";
    }
    return 0;
}