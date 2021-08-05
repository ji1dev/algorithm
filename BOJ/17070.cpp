// 17070번_파이프 옮기기
#include <iostream>
using namespace std;
int n, cnt;
int di[] = {0, 1, 1}, dj[] = {1, 0, 1}; // 가로, 세로, 대각선 이동
bool map[17][17];
bool check(int i, int j, int prev, int next){
    if((prev==0 && next==1) || (prev==1 && next==0)) return false; // 가로, 세로 이동 제약
    if((next == 2) && (map[i+1][j] || map[i][j+1])) return false; // 대각선 이동 제약
    return true;
}
void dfs(int i, int j, int dir){
    if(i==n && j==n){
        cnt++;
        return;
    }
    for(int k=0; k<3; ++k){
        if(!check(i, j, dir, k)) continue; // k방향으로 이동 가능한지 확인
        int ni = i+di[k];
        int nj = j+dj[k];
        if(ni<1 || ni>n || nj<1 || nj>n || map[ni][nj]) continue; // 범위 벗어나거나 벽에 가로막히는 경우
        dfs(ni, nj, k); // k방향으로 밀어서 (ni, nj)로 이동
    }
}
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j) cin >> map[i][j];
    }
    dfs(1, 2, 0); // 파이프의 끝 좌표와 방향(0:가로, 1:세로, 2:대각)
    cout << cnt;
    return 0;
}