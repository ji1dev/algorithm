// 17836번_공주님을 구해라!
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 101
#define MP make_pair
using namespace std;
int n, m, t, ans, map[MAX][MAX];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
int visited[MAX][MAX][2]; // [][][0] = 검 X / [][][1] = 검 획득
queue<pair<pair<int, int>, pair<int, bool> > > q;
void solve(){
    q.push(MP(MP(0, 0), MP(0, false)));
    visited[0][0][0] = 1;
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int c = q.front().second.first; // 이동 칸수
        bool s = q.front().second.second; // 검 획득 여부
        q.pop();
        if(map[i][j] == 2) s = true; // 검 획득 표시
        if(i==(n-1) && j==(m-1)){ // t초 이내에 도착한 경우
            if(c <= t) ans = c;
            break;
        }
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=m) continue;
            if(visited[ni][nj][s]) continue;
            if(s){ // 검 획득한 경우 벽 상관없이 가면 됨
                visited[ni][nj][s] = c+1;
            }
            else{ // 검 없는 경우 벽 통과 못함
                if(map[ni][nj] == 1) continue;
                visited[ni][nj][s] = c+1;
            }
            q.push(MP(MP(ni, nj), MP(c+1, s)));
        }
    }
    if(ans) cout << ans;
    else cout << "Fail";
}
int main(){
    cin >> n >> m >> t;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j];
        }
    }
    solve();
    return 0;
}
