// 2581번_소수
#include <iostream>
#include <memory.h>
#define MAX 10000
using namespace std;
bool isPrime[MAX+1], isFirst;
int m, n, min_num, sum;
int main(){
    cin >> m >> n;
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    isFirst = true;
    for(int i=2; i*i<=MAX; ++i){
        if(isPrime[i]){
            for(int j=i*2; j<=MAX; j+=i) isPrime[j] = false;
        }
    }
    for(int i=m; i<=n; ++i){
        if(isPrime[i]){
            if(isFirst){
                min_num = i;
                isFirst = false;
            }
            sum += i;
        }
    }
    if(sum) cout << sum << "\n" << min_num;
    else cout << -1;
    return 0;
}