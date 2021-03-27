// 2225번_합분해
#include <iostream>
#define M 1000000000
using namespace std;
int main(){
    int n, k;
    long long dp[201][201] = {0, };
    cin >> n >> k;
    for(int b=0; b<=k; ++b) dp[0][b] = 1;
    for(int a=1; a<=n; ++a){
        for(int b=1; b<=k; ++b){
            // dp[n][k]=dp[n-1][k]+dp[n][k-1]
            dp[a][b] = dp[a-1][b] + dp[a][b-1];
            dp[a][b] %= M;
        }
    }
    cout << dp[n][k];
    return 0;
}