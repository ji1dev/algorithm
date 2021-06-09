// 10026번_적록색약
#include <iostream>
#include <memory.h>
using namespace std;
char fig[100][100];
bool visited[100][100];
int dx[] = {0, 0, -1, 1}; // 상, 하, 좌, 우
int dy[] = {-1, 1, 0, 0};
int n, ans1, ans2;
void dfs(int x, int y){
    char current = fig[x][y];
    visited[x][y] = true;
    for(int k=0; k<4; ++k){
        int new_x = x + dx[k];
        int new_y = y + dy[k];
        // 그림판을 벗어나지 않고, 새 좌표가 같은 색이며 아직 방문하지 않은 경우
        if(new_x>=0 && new_x<n && new_y>=0 && new_y<n){
            if(fig[new_x][new_y]==current && !visited[new_x][new_y]){
                dfs(new_x, new_y); // 계속 탐색함
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            scanf("%1s", &fig[i][j]);
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            // 방문하지 않은 좌표 기준, 같은 색깔이 모여있는 구역의 개수를 셈
            if(!visited[i][j]){
                dfs(i, j);
                ans1++;
            }
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            visited[i][j] = false; // 방문 여부 초기화
            // 적록색약의 경우 R픽셀을 모두 G픽셀로 변경
            if(fig[i][j] == 'R') fig[i][j] = 'G';
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(!visited[i][j]){
                dfs(i, j);
                ans2++;
            }
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}