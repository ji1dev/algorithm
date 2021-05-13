// 7576번_토마토
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int dx[] = {0, 1, 0, -1}; // top, right, bottom, left
    int dy[] = {-1, 0, 1, 0};
    int tomato[1001][1001], visited[1001][1001]; // 방문 기록(일자)
    int n, m, cnt = 0;
    queue <pair<int, int> > q;
    cin >> m >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> tomato[i][j];
            visited[i][j] = -1; // 모든 칸의 방문 기록 초기값 -1
            if(tomato[i][j] == 1){
                visited[i][j] = 0; // 시작 지점의 방문 기록 0으로 설정
                q.push(make_pair(i, j)); // 시작 좌표 큐에 push
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; ++i){
            // top, right, bottom, left 칸 확인
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m){ // 상자 범위
                if(tomato[nx][ny]==0 && visited[nx][ny]==-1){
                    // 현재 칸의 토마토가 익지 않았고, 방문기록이 없는 경우
                    // 일자 계산을 위해 이전 칸의 (방문 기록+1)하고 좌표를 큐에 push
                    visited[nx][ny] = visited[x][y]+1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(tomato[i][j]==0 && visited[i][j]==-1){
                // 익지 않은 토마토가 있고 해당 칸에 방문한 기록이 없다면 토마토가 모두 익지 못하는 상황
                cout << -1;
                return 0;
            }
            cnt = max(cnt, visited[i][j]); // 방문 기록 확인하며 소요 일자 갱신
        }
    }
    cout << cnt;
    return 0;
}