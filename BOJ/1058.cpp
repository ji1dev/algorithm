// 1058번_친구
#include <iostream>
#include <algorithm>
#include <string>
#define INF 987654321
#define MAX 51
using namespace std;
int n, path[MAX][MAX];
void solve(){
    for(int k=1; k<=n; ++k){ // Floyd
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(i == j) continue;
                if(path[i][k] && path[k][j])
                    path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; ++i){
        int cnt = 0;
        for(int j=1; j<=n; ++j){
            if(path[i][j] <= 2) cnt++; // 2-친구 수 count
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            path[i][j] = INF;
        }
    }
    for(int i=1; i<=n; ++i){
        string s;
        cin >> s;
        for(int j=0; j<n; ++j){
            if(s[j] == 'Y') path[i][j+1] = 1;
        }
    }
    // for(int i=1; i<=n; ++i){
    //     for(int j=1; j<=n; ++j){
    //         if(path[i][j]==INF) cout << 0;
    //         else cout << path[i][j];
    //     }
    //     cout << "\n";
    // }
    solve();
    return 0;
}