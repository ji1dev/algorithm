// 1149번_RGB거리
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, cost[1001][3] = {0, }, dp[1001][3] = {0, }; 
    cin >> n;   
    for(int i=1; i<=n; ++i){
        for(int j=0; j<3; ++j){
            cin >> cost[i][j];
        }
    }
    for(int j=0; j<3; ++j) dp[1][j] = cost[1][j];
    for(int i=2; i<=n; ++i){
        // i번째 집의 색과 i-1번째 집의 색은 달라야 됨
        dp[i][0] = cost[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = cost[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = cost[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }
    // 26+57+13 = 96 (R -> B -> R)
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);
    return 0;
}