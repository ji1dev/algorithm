// 2178번_미로 탐색
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = {0, 1, 0, -1}; // top, right, bottom, left
int dy[] = {-1, 0, 1, 0};
int n, m, a[100][100], visited[100][100];
queue <pair<int, int> > q;
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            scanf("%1d", &a[i][j]); // 붙어서 들어오는 입력 하나씩 받기
        }
    }
    visited[0][0] = 1; // 칸을 셀 때 시작 위치도 포함
    q.push(make_pair(0, 0));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; ++i){
            for(int j=0; j<4; ++j){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(a[nx][ny]==1 && visited[nx][ny]==0){
                        // 이동할 수 있는 칸이고 아직 방문하지 않았다면
                        // 이전 위치로 이동할 때 지나야 하는 칸 수 + 1처리하고 큐에 push
                        visited[nx][ny] = visited[x][y]+1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    cout << visited[n-1][m-1]; // 도착 위치까지 이동할 때 지나야 하는 칸 수
    return 0;
}