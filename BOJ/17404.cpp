// 17404번_RGB거리 2
#include <iostream>
#include <algorithm>
#define L 987654321
using namespace std;
int n, cost[1001][3], dp[1001][3], min_cost;
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        for(int j=0; j<3; ++j){ // 0:R, 1:G, 2:B
            cin >> cost[i][j];
        }
    }
    // 첫 집의 색깔 고정하고 나머지 집을 칠함
    min_cost = L;
    for(int c=0; c<3; ++c){
        // 첫 집의 색깔을 고정하기 위해 특정 색을 선택한 뒤, 나머지 색을 칠하는 경우에 아주 큰 값을 넣어둠
        // 최솟값을 선택하는 과정에서 나머지 색을 칠하는 경우는 자연스럽게 제외됨
        for(int j=0; j<3; ++j){
            if(j == c) dp[1][j] = cost[1][j];
            else dp[1][j] = L;
        }
        // i번째 집의 색과 i-1번째 집의 색은 다름
        for(int i=2; i<=n; ++i){
            dp[i][0] = cost[i][0]+min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = cost[i][1]+min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = cost[i][2]+min(dp[i-1][0], dp[i-1][1]);
        }
        // 첫 집과 마지막 집 색이 같은 경우 최소 비용 갱신 X
        for(int j=0; j<3; ++j){
            if(j == c) continue;
            min_cost = min(min_cost, dp[n][j]);
        }
    }
    cout << min_cost;
    return 0;
}