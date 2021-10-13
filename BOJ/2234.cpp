// 2234번_성곽
#include <iostream>
#include <algorithm>
#include <queue>
#define MP make_pair
using namespace std;
int di[] = {0, -1, 0, 1}; // 서, 북, 동, 남 순서
int dj[] = {-1, 0, 1, 0};
int map[51][51], visited[51][51], r_size[51];
int n, m, cnt, max_s, max_sd;
int bfs(int si, int sj){
    int s = 1; // 현재 방 크기
    queue< pair<int, int> > q;
    q.push(MP(si, sj));
    visited[si][sj] = cnt; // 현재 방 번호
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            // 맵 밖으로 나가거나, 이동하려는 방향에 벽이 있으면 넘어감
            if(ni<0 || ni>=m || nj<0 || nj>=n) continue;
            if(map[i][j] & (1<<k)) continue;
            if(visited[ni][nj] == 0){
                q.push(MP(ni, nj));
                visited[ni][nj] = cnt;
                s++;
            }
        }
    }
    r_size[cnt] = s;
    return s;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(visited[i][j] == 0){
                cnt++; // 방 번호
                max_s = max(max_s, bfs(i, j)); // 최대 방 크기 갱신
            }
        }
    }
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<4; ++k){
                int ni = i+di[k];
                int nj = j+dj[k];
                if(ni<0 || ni>=m || nj<0 || nj>=n) continue;
                // 넘어가려는 방 사이에 벽이 있고, 다른 방이면 벽 부수고 방 크기 합쳐서 계산
                if(map[i][j] & (1<<k)){
                    int r1 = visited[i][j], r2 = visited[ni][nj];
                    if(r1 == r2) continue;
                    max_sd = max(max_sd, r_size[r1]+r_size[r2]);
                }
            }
        }
    }
    cout << cnt << "\n" << max_s << "\n" << max_sd;
    return 0;
}