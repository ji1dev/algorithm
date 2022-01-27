// 14442번_벽 부수고 이동하기 2
#include <iostream>
#include <tuple>
#include <queue>
#define MAX 1001
#define MT make_tuple
using namespace std;
int n, m, k, map[MAX][MAX], visited[MAX][MAX][11];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
queue<tuple<int, int, int> > q;
void solve(){
    q.push(MT(0, 0, 0)); // 좌표와 부순 벽 개수
    visited[0][0][0] = 1;
    while(!q.empty()){
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int b = get<2>(q.front());
        q.pop();
        if(i==(n-1) && j==(m-1)){
            cout << visited[i][j][b]; // b개 벽을 부수고 n, m에 도달
            return;
        }
        for(int d=0; d<4; ++d){
            int ni = i+di[d];
            int nj = j+dj[d];
            if(ni<0 || ni>=n || nj<0 || nj>=m) continue;
            // 새 좌표가 빈 칸이고, 아직 방문하지 않은 경우
            if(map[ni][nj]==0 && !visited[ni][nj][b]){
                visited[ni][nj][b] = visited[i][j][b]+1; // 부순 벽 개수는 변함 없음
                q.push(MT(ni, nj, b));
            }
            // 새 좌표가 벽이고, 부순 벽 개수가 k개 미만이고, 새로 벽을 부순 뒤의 좌표를 아직 방문하지 않은 경우
            else if(map[ni][nj]==1 && b<k && !visited[ni][nj][b+1]){
                visited[ni][nj][b+1] = visited[i][j][b]+1; // 벽 새로 부숨
                q.push(MT(ni, nj, b+1));
            }
        }
    }
    cout << -1; // 불가능한 경우
}
int main(){
    cin >> n >> m >> k;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            scanf("%1d", &map[i][j]);
        }
    }
    solve();
    return 0;
}