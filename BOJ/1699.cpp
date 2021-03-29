// 1699번_제곱수의 합
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, dp[100001] = {0, };
    cin >> n;
    dp[0] = 0;
    for(int i=1; i<=n; ++i){
        dp[i] = i; // 1의 제곱수의 합으로 i를 만드는 경우
        for(int j=1; j*j<=i; ++j){
            // i에 가장 가까운 j의 제곱수를 빼고 어떤 제곱수 하나를 더해 i를 만드는 경우와 비교
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    cout << dp[n];
    return 0;
}