// 9461번_파도반 수열
#include <iostream>
using namespace std;
int main(){
    int t, n;
    long long dp[101] = {0, };
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    cin >> t;
    for(int i=4; i<101; ++i){
        dp[i] = dp[i-2]+dp[i-3];
    }
    while(t--){
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}