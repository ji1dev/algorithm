// 11048번_이동하기
#include <iostream>
#include <algorithm>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, m, map[1001][1001], dp[1001][1001];
int main(){
    F_IO;
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin >> map[i][j];
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            dp[i][j] += max(max(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1])+map[i][j];
        }
    }
    cout << dp[n][m];
    return 0;
}