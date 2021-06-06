// 7569번_토마토
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct position{
    int h;
    int n;
    int m;
}POS;
int main(){
    int h, m, n, new_h, new_m, new_n, ans = 0;
    int tomato[101][101][101], visited[101][101][101];
    int dh[] = {0, 0, 0, 0, -1, 1};
    int dn[] = {0, 0, -1, 1, 0, 0};
    int dm[] = {-1, 1, 0, 0, 0, 0}; // 상, 하, 좌, 우, 윗줄, 아랫줄
    POS cur_pos, new_pos;
    queue<POS> q;
    cin >> m >> n >> h;
    for(int i=0; i<h; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<m; ++k){
                cin >> tomato[i][j][k]; // i층, j행, j열의 토마토 상태
                visited[i][j][k] = -1; // 방문기록 초기값 -1
                if(tomato[i][j][k] == 1){
                    // 입력시 익어있는 토마토는 탐색의 시작점이 됨
                    visited[i][j][k] = 0; 
                    cur_pos.h = i;
                    cur_pos.n = j;
                    cur_pos.m = k;
                    q.push(cur_pos);
                }
            }
        }
    }
    while(!q.empty()){
        cur_pos = q.front();
        q.pop();
        for(int i=0; i<6; ++i){
            new_h = cur_pos.h + dh[i]; // 6방향으로 새 좌표 계산
            new_n = cur_pos.n + dn[i];
            new_m = cur_pos.m + dm[i];
            if(new_h>=0 && new_h<h && new_n>=0 && new_n<n && new_m>=0 && new_m<m){ // 칸 범위에 들어오는지 확인
                if(tomato[new_h][new_n][new_m]==0 && visited[new_h][new_n][new_m]==-1){
                    // 새 좌표의 토마토가 익지 않았고, 처음 방문하는 칸이면 (이전 칸+1)로 방문 기록을 설정하고 새 좌표를 큐에 push 
                    visited[new_h][new_n][new_m] = visited[cur_pos.h][cur_pos.n][cur_pos.m]+1;
                    new_pos.h = new_h;
                    new_pos.n = new_n;
                    new_pos.m = new_m;
                    q.push(new_pos);
                }
            }
        }
    }
    for(int i=0; i<h; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<m; ++k){
                if(tomato[i][j][k]==0 && visited[i][j][k] == -1){
                    // 탐색 끝낸 후 익지 않은 토마토가 있고, 해당 칸에 방문한 기록이 없으면 토마토가 모두 익지 못한 것
                    cout << -1;
                    return 0;
                }
                ans = max(ans, visited[i][j][k]); // 토마토가 모두 익기까지 걸린 날짜
            }
        }
    }
    cout << ans;
    return 0;
}