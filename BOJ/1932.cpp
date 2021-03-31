// 1932번_정수 삼각형
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, ans = 0;
    int in[501][501] = {0, }, dp[501][501] = {0, };
    cin >> n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=i; ++j){
            cin >> in[i][j];
        }
    }
    dp[1][1] = in[1][1];
    for(int i=2; i<=n; ++i){
        for(int j=1; j<=i; ++j){
            // dp[i][j] = i층 j번째 수 까지의 누적합 (위에서부터 1층, 2층, ...)
            // i층 j번째 수 기준으로 max(대각선 왼쪽 위 까지의 누적합, 대각선 오른쪽 위 까지의 누적합)
            // 를 구하고 i층 j번째 수를 더함
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j])+in[i][j];
        }
    }
    for(int j=1; j<=n; ++j){
        // n층의 n개 누적합 중 가장 큰 값이 정답
        ans = max(ans, dp[n][j]);
    }
    cout << ans;
    return 0;
}