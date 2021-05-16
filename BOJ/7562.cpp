// 7562번_나이트의 이동
#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int visited[300][300];
queue <pair<int, int> > q;
void bfs(){
    int l, sx, sy, tx, ty;
    cin >> l >> sx >> sy >> tx >> ty;
    visited[sx][sy] = 1;
    q.push(make_pair(sx, sy));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<8; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<l && ny>=0 && ny<l){
                // 나이트가 이동할 수 있는 좌표이고 아직 방문하지 않았다면
                // 방문 기록을 현재 좌표까지 이동한 횟수+1로 갱신하고 큐에 push
                if(!visited[nx][ny]){
                    visited[nx][ny] = visited[x][y]+1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    cout << visited[tx][ty]-1 << "\n"; // target좌표의 방문 기록 확인
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        memset(visited, 0, sizeof(visited)); // tc가 여러개 이므로 초기화 필수
        bfs();
    }
    return 0;
}