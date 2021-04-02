// 15988번_1, 2, 3 더하기 3
#include <iostream>
#define M 1000000009
#define MAX 1000001
using namespace std;
int main(){
    int t, n;
    long long dp[MAX] = {0, };
    cin >> t;
    dp[1] = 1; // 1
    dp[2] = 2; // 1+1, 2
    dp[3] = 4; // 1+1+1, 2+1, 1+2, 3
    for(int i=4; i<=MAX; ++i){
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%M;
    }
    while(t--){
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}