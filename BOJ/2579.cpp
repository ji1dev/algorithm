// 2579번_계단 오르기
#include <iostream>
#include <algorithm>
using namespace std;
int n, step[301], dp[301];
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> step[i];
    dp[1] = step[1];
    dp[2] = max(step[2], step[1]+step[2]); // 바로 두 번째 계단으로 vs 첫 번째 계단까지 올라와서 한 계단
    dp[3] = max(step[1]+step[3], step[2]+step[3]); // 첫 번째 밟고 두 계단 vs 바로 두 번째 계단으로 올라와서 한 계단

    for(int i=4; i<=n; ++i){
        // 마지막 n번째 계단 기준으로 생각
        // 1. n-2번째까지 올라와서 두 계단
        // 2. n-1번째까지 올라와서 한 계단 = n-3번째까지 올라와서 두 계단 (연속으로 세 개의 계단 밟을 수 없으므로)
        dp[i] = max(dp[i-2]+step[i], dp[i-3]+step[i-1]+step[i]);
    }
    cout << dp[n];
    return 0;
}