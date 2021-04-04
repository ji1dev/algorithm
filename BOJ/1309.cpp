// 1309번_동물원
#include <iostream>
#define M 9901
using namespace std;
int main(){
    int n, dp[100001] = {0, };
    cin >> n;
    dp[1] = 3;
    dp[2] = 7;
    for(int i=3; i<=n; ++i){
        dp[i] = (dp[i-1]*2 + dp[i-2])%M;
    }
    cout << dp[n];
    return 0;
}