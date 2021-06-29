// 2293번_동전 1
#include <iostream>
using namespace std;
int n, k, coin[101], dp[10001];
int main(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> coin[i];
    // dp[a] = a원을 만드는 경우의 수
    dp[0] = 1;
    for(int i=1; i<=n; ++i){
        // a원을 만들기 위해 필요한 코인은 a원 이상이어야 함 (j 초기값이 coin[i]인 이유)
        for(int j=coin[i]; j<=k; ++j){
            // 기존 j원을 만들기 위한 경우의 수에 새롭게 i번째 코인을 포함시켜서 j원을 만드는 경우 추가
            // 즉 i번째 코인의 가치를 뺀 액수를 만드는 경우의 수를 더해나감
            dp[j] = dp[j]+dp[j-coin[i]];
        }
    }
    cout << dp[k];
    return 0;
}