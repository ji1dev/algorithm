// 4963번_섬의 개수
#include <iostream>
#include <memory.h>
using namespace std;
int w, h, map[50][50];
int di[] = {-1, 1, 0, 0, -1, -1, 1, 1}; // 가로, 세로, 대각선
int dj[] = {0, 0, -1, 1, -1, 1, 1, -1};
bool visited[50][50];
void dfs(int i, int j){
    visited[i][j] = true; // 땅 방문 처리
    for(int k=0; k<8; ++k){ // 8방향의 땅 확인
        int ni = i+di[k];
        int nj = j+dj[k];
        if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
        if(!visited[ni][nj] && map[ni][nj]==1) dfs(ni, nj);
    }
}
int main(){
    while(1){
        int island = 0;
        memset(visited, false, sizeof(visited));
        cin >> w >> h;
        if(w==0 && h==0) break;
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                cin >> map[i][j];
            }
        }
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                if(!visited[i][j] && map[i][j]==1){
                    dfs(i, j); // dfs 마치고 나오면 하나의 섬을 모두 방문한 것
                    island++;
                }
            }
        }
        cout << island << "\n";
    }
    return 0;
}