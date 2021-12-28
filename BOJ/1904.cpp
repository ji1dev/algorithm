// 1904번_01타일
#include <iostream>
#define M 15746
using namespace std;
int n, dp[1000001];
int main(){
    cin >> n;
    dp[1] = 1; // 1
    dp[2] = 2; // 11, 00
    for(int i=3; i<=n; ++i){
        // i-2번째에 00타일, i-1번째에 1타일 붙이면 중복없이 수열 개수 구할 수 있음
        // (짝수 -> 홀수, 홀수 -> 짝수로 계산되므로)
        dp[i] = (dp[i-2]+dp[i-1])%M;
    }
    cout << dp[n];
    return 0;
}