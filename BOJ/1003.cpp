// 1003번_피보나치 함수
#include <iostream>
using namespace std;
int main(){
    // fib(0) = 1, 0
    // fib(1) = 0, 1
    // fib(2) = fib(1)+fib(0) = 1, 1
    // fib(3) = fib(2)+fib(1) = 1, 2
    // fib(4) = fib(3)+fib(2) = 2, 3
    int t, n, dp[41]={0, 1};
    for(int i=2; i<41; i++) dp[i] = dp[i-1]+dp[i-2];
    cin >> t;
    for(int i=0; i<t; ++i){
        // fib(n)과정에서 0출력되는 횟수 dp[n-1], 1출력되는 횟수 dp[n]
        cin >> n;
        if(n == 0) printf("%d %d\n", 1, 0);
        else if(n == 1) printf("%d %d\n", 0, 1);
        else printf("%d %d\n", dp[n-1], dp[n]);
    }
    return 0;
}