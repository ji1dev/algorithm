// 1012번_유기농 배추
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[] = {0, 1, 0, -1}; // top, right, bottom, left
int dy[] = {-1, 0, 1, 0};
int map[50][50];
int t, m, n, k, cnt;
void init(){
    int x, y;
    cnt = 0;
    cin >> m >> n >> k;
    for(int i=0; i<k; ++i){
        cin >> x >> y;
        map[y][x] = 1;
    }
}
void dfs(int y, int x){
    map[y][x] = 0; // 배추 확인 처리
    for(int i=0; i<4; ++i){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny>=0 && ny<n && nx>=0 && nx<m){
            // 범위 내에 있고 아직 방문하지 않은 곳이라면 진행
            if(map[ny][nx] == 1) dfs(ny, nx);
        }
    }
}
int main(){
    cin >> t;
    for(int tc=0; tc<t; ++tc){
        init();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(map[i][j] == 1){
                    // 어떤 배추의 인접 배추들을 모두 확인한 뒤 한 집합으로 count
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}