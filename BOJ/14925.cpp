// 14925번_목장 건설하기
#include <iostream>
#include <algorithm>
using namespace std;
int m, n, ans, map[1001][1001], dp[1001][1001];
int main(){
    cin >> m >> n;
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            cin >> map[i][j];
        }
    }
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(map[i][j] == 0){
                // 왼쪽, 위쪽, 대각선의 칸이 포함된 정사각형의 변 길이 중 최솟값에 +1
                dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1])+1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}