// 1743번_음식물 피하기
#include <iostream>
#include <algorithm>
#include <queue>
#define MP make_pair
using namespace std;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
int n, m, k, max_cnt;
bool map[101][101], visited[101][101];
void bfs(int si, int sj){
    int cnt = 1;
    queue< pair<int, int> > q;
    q.push(MP(si, sj));
    visited[si][sj] = true;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=m) continue;
            // 음식물 있는 칸이고 아직 방문 안했으면 큐에 넣고 음식물 덩어리의 크기 증가
            if(map[ni][nj] && !visited[ni][nj]){
                visited[ni][nj] = true;
                q.push(MP(ni, nj));
                cnt++;
            }
        }
    }
    max_cnt = max(max_cnt, cnt); // 음식물 덩어리의 최대 크기 갱신
}
int main(){
    cin >> n >> m >> k;
    for(int i=0; i<k; ++i){
        int r, c;
        cin >> r >> c;
        map[r-1][c-1] = true;
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            // bfs 돌 때마다 다른 음식물 덩어리를 확인하게 됨
            if(map[i][j] && !visited[i][j]) bfs(i, j);
        }
    }
    cout << max_cnt;
    return 0;
}