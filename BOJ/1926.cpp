// 1926번_그림
#include <iostream>
#include <algorithm>
#define MP make_pair
using namespace std;
int n, m, cnt, p_size, board[501][501];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
bool visited[501][501];
int dfs(int i, int j){
    int s = 1;
    visited[i][j] = true;
    for(int k=0; k<4; ++k){
        int ni = i+di[k];
        int nj = j+dj[k];
        if(board[ni][nj]==1 && !visited[ni][nj]){
            s += dfs(ni, nj);
        }
    }
    return s;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> board[i][j];
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(board[i][j]==1 && !visited[i][j]){
                cnt++; // 그림 개수
                p_size = max(p_size, dfs(i, j)); // 최대 그림 넓이 갱신
            }
        }
    }
    cout << cnt << "\n" << p_size;
    return 0;
}