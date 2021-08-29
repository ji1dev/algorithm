// 17086번_아기 상어 2
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#define MP make_pair
using namespace std;
int n, m, ans, map[51][51];
int di[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dj[] = {0, 0, -1, 1, -1, 1, 1, -1};
bool visited[51][51];
void bfs(int si, int sj){
    memset(visited, false, sizeof(visited));
    queue< pair< pair<int, int>, int > > q; // 좌표, 이동 거리
    q.push(MP(MP(si, sj), 0));
    visited[si][sj] = true;
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(map[i][j] == 1){ // 상어 만나면 안전 거리의 최댓값 갱신
            ans = max(ans, d);
            return;
        }
        for(int k=0; k<8; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=m) continue;
            if(!visited[ni][nj]){
                q.push(MP(MP(ni, nj), d+1));
                visited[ni][nj] = true;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            // 빈 칸 만나면 해당 칸 기준으로 bfs시작
            if(map[i][j] == 0) bfs(i, j);
        }
    }
    cout << ans;
    return 0;
}