// 9084번_동전
#include <iostream>
#include <memory.h>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    F_IO;
    int t;
    cin >> t;
    while(t--){
        int n, m, coin[21] = {0, }, dp[10001] = {0, };
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> coin[i];
        cin >> m;
        dp[0] = 1;
        // dp[j] = j원을 만드는 방법의 수
        // i번째 동전을 더해서 j원 만들 수 있는 경우를 목표금액인 m원까지 계속 더해나감
        for(int i=1; i<=n; ++i){
            for(int j=coin[i]; j<=m; ++j){
                dp[j] = dp[j]+dp[j-coin[i]];
            }
        }
        cout << dp[m] << "\n";
    }
    return 0;
}