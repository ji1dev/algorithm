// 18290번_NM과 K (1)
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k, mx_sum, map[11][11];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
bool visited[11][11];
bool isAdj(int i, int j){ // 인접된 칸 중 선택된 칸이 있는지 확인
    for(int k=0; k<4; ++k){
        int ni = i+di[k], nj = j+dj[k];
        if(ni<0 || ni>=n || nj<0 || nj>=m) continue;
        if(visited[ni][nj]) return true;
    }
    return false;
}
void solve(int sum, int cnt){
    if(cnt == k){
        mx_sum = max(mx_sum, sum);
        return;
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(visited[i][j] || isAdj(i, j)) continue;
            visited[i][j] = true;
            solve(sum+map[i][j], cnt+1);
            visited[i][j] = false;
        }
    }
}
int main(){
    cin >> n >> m >> k;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j];
        }
    }
    mx_sum = -987654321;
    solve(0, 0);
    cout << mx_sum; // 선택한 칸에 들어있는 수를 모두 더한 값의 최댓값 
    return 0;
}