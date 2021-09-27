// 1303번_전쟁 - 전투
#include <iostream>
#include <cmath>
using namespace std;
int n, m, w_po, b_po;
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
char map[101][101];
bool visited[101][101];
int dfs(int i, int j, int team){
    int cnt = 1; // 모든 자리에는 병사가 한 명 있음
    visited[i][j] = true;
    for(int k=0; k<4; ++k){
        int ni = i+di[k];
        int nj = j+dj[k];
        if(ni<0 || ni>=m || nj<0 || nj>=n || visited[ni][nj]) continue;
        if(map[ni][nj] == team) cnt += dfs(ni, nj, team);
    }
    return cnt; // 모여있는 같은 팀의 인원 수
}
int main(){
    cin >> n >> m; // 가로, 세로
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            scanf("%1s", &map[i][j]);
        }
    }
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(!visited[i][j]){
                if(map[i][j] == 'W') w_po += pow(dfs(i, j, 'W'), 2);
                else b_po += pow(dfs(i, j, 'B'), 2);           
            }
        }
    }
    cout << w_po << " " << b_po;
    return 0;
}