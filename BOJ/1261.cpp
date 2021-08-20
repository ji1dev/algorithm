// 1261번_알고스팟
#include <iostream>
#include <queue>
#define MP make_pair
#define INF 987654321
using namespace std;
int n, m, ans, map[101][101];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
bool visited[101][101];
// 부순 벽 개수와 현재 칸의 좌표
priority_queue< pair<int, pair<int, int> >, vector< pair<int, pair<int, int> > >, greater< pair<int, pair<int, int> > > > pq;
void bfs(){
    pq.push(MP(0, MP(0, 0)));
    visited[0][0] = true;
    while(!pq.empty()){
        int b = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();
        if(i==n-1 && j==m-1){
            ans = b;
            return;
        }
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            
            if(ni<0 || ni>=n || nj<0 || nj>=m || visited[ni][nj]) continue;
             // 새 좌표가 벽인 경우 벽 뚫음
            if(map[ni][nj] == 1) pq.push(MP(b+1, MP(ni, nj)));          
            else pq.push(MP(b, MP(ni, nj)));
            visited[ni][nj] = true;
        }
    }
}
int main(){
    cin >> m >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            scanf("%1d", &map[i][j]);
        }
    }
    bfs();
    cout << ans;
    return 0;
}