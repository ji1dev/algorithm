// 2589번_보물섬
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 51
#define MP make_pair
using namespace std;
int n, m, ans, di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
char map[MAX][MAX];
int bfs(int si, int sj){
    // BFS로 육지를 최단거리로 이동하며, 시작칸에서 가장 멀리 떨어진 칸 까지의 거리를 구함
    int visited[MAX][MAX] = {0, }, dist = 0;
    queue<pair<int, int> > q;
    q.push(MP(si, sj));
    visited[si][sj] = 1;
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k], nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=m || visited[ni][nj]) continue;
            if(map[ni][nj] != 'L') continue;
            visited[ni][nj] = visited[i][j]+1;
            dist = max(dist, visited[ni][nj]);
            q.push(MP(ni, nj));
        }
    }
    return dist-1;
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
            if(map[i][j] == 'L'){
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans;
    return 0;
}