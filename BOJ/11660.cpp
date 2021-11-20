// 11660번_구간 합 구하기 5
#include <iostream>
using namespace std;
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n, m, dp[1025][1025];
int main(){
    F_IO;
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            int val;
            cin >> val;
            // 누적합 구할 때 중복으로 더해지는 값을 빼주고 현재 값을 더함
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+val;
        }
    }
    for(int k=0; k<m; ++k){
        int i1, i2, j1, j2, ans;
        cin >> i1 >> j1 >> i2 >> j2;
        // (i2, j2)까지의 영역에서 (i1, j1)보다 작은 좌표 영역의 값을 모두 빼줌
        ans = dp[i2][j2]-dp[i1-1][j2]-(dp[i2][j1-1]-dp[i1-1][j1-1]);
        cout << ans << "\n";
    }
    return 0;
}