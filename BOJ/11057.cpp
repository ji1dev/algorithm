// 11057번_오르막 수
#include <iostream>
#include <cmath>
#define M 10007
using namespace std;
int main(){
    // dp[i][j] = 끝 자리가 j인 i자리 오르막 수의 개수
    // dp[1][0...9] = 각 1개
    int n, dp[1001][10]={0, }, sum = 0;
    cin >> n;
   
    for(int j=0; j<=9; ++j) dp[1][j] = 1;
    // j로 끝나는 i+1자리의 오르막 수는 i자리 오르막 수 끝에 j~9까지의 수를 붙여서 만들 수 있음
    // 인접한 수가 같아도 오르막 수 (e.g 112)
    for(int i=2; i<=n; ++i){
        for(int j=0; j<=9; ++j){
            for(int k=j; k<=9; ++k){
                // e.g) dp[2][1] = dp[1][1] + ... + dp[1][9]
                dp[i][k] += dp[i-1][j]; 
                dp[i][k] %= M;
            }
        }
    }
    for(int j=0; j<=9; ++j) sum += dp[n][j];
    cout << sum%M;
    return 0;
}