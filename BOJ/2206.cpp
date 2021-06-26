// 2206번_벽 부수고 이동하기
#include <iostream>
#include <queue>
#define MP make_pair
using namespace std;
// visited[][][0] : 벽을 부수지 않았을 때 방문 기록 (경로의 길이)
// visited[][][1] : 벽을 부순 뒤 방문 기록 (경로의 길이)
int n, m, map[1000][1000], visited[1000][1000][2]; 
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
void bfs(){
    queue< pair< pair<int, int>, bool> > q;
    q.push(MP(MP(0, 0), false)); // 좌표와 벽 부쉈는지 여부 (true:부숨, false:안 부숨)
    visited[0][0][1] = 1;
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        bool isBroken = q.front().second; // 벽 부쉈는지 여부
        q.pop();
        // 목적지 도달했을 경우 경로 길이 배열의 값 출력
        // 이 때 isBroken 여부에 따라 벽을 부수거나, 부수지 않은 결과를 출력하게 됨
        if((i==n-1) && (j==m-1)){
            // 시작, 종료칸 또한 경로 길이에 포함
            cout << visited[n-1][m-1][isBroken]+1; 
            return;
        }
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=m) continue;
            // 새 좌표가 벽이고, 아직 부수지 않은 경우
            if(map[ni][nj]==1 && !isBroken){
                // (원래 좌표까지 경로 길이 + 1)값을 새 좌표까지의 경로 길이로 설정
                // 이 때 벽을 부순 뒤 방문한 것이므로 visited[ni][nj][0]에 저장함 
                q.push(MP(MP(ni, nj), true)); // 벽을 부숨
                visited[ni][nj][1] = visited[i][j][0]+1;
            }
            // 새 좌표가 길이고, 아직 방문하지 않은 경우 (벽을 부쉈을수도, 부수지 않았을 수도 있음)
            else if(map[ni][nj]==0 && visited[ni][nj][isBroken]==0){
                q.push(MP(MP(ni, nj), isBroken)); // 벽 부쉈는지 여부는 그대로임
                visited[ni][nj][isBroken] = visited[i][j][isBroken]+1;
            }
        }
    }
    cout << -1; // 목적지 도달이 불가능한 경우
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            scanf("%1d", &map[i][j]);
        }
    }
    bfs();
    return 0;
}