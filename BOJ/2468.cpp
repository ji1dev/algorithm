// 2468번_안전 영역
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int n, height, safe_area, ans;
int min_h = 101, max_h = 0, map[100][100];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
bool visited[100][100];
void dfs(int i, int j){
    visited[i][j] = true;
    for(int k=0; k<4; ++k){
        // 상하좌우 인접 좌표가 안전하다면 해당 좌표로 안전 영역을 넓혀가며 dfs진행
        int ni = i+di[k];
        int nj = j+dj[k];
        if(ni>=0 && ni<n && nj>=0 && nj<n){
            if(!visited[ni][nj] && map[ni][nj]>height) dfs(ni, nj);
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> map[i][j];
            if(max_h < map[i][j]) max_h = map[i][j]; // 강수량 테스트할 최대 높이
        }
    }
    for(int h=0; h<=max_h; ++h){
        // 각 강수량 마다 안전영역의 개수를 구함
        safe_area = 0;
        height = h;
        memset(visited, false, sizeof(visited)); // 방문기록 초기화
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                // 방문하지 않았고, 현재 영역이 현재 강수량보다 높으면 안전 영역에 들어감
                // dfs 탈출하면 현재 영역 기준 인접한 곳에 안전 영역이 없다는 것이므로 하나의 안전 영역 끝
                if(!visited[i][j] && map[i][j]>height){
                    dfs(i, j);
                    safe_area++; 
                }
            }
        }
        ans = max(ans, safe_area); // 안전 영역의 최대 개수 계산
    }
    cout << ans;
    return 0;
}