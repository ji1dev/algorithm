// 2665번_미로 만들기
#include <iostream>
#include <queue>
#include <memory.h>
#define MAX 51
#define MP make_pair
using namespace std;
int n, map[MAX][MAX], visited[MAX][MAX]; // 방문기록 (벽 몇개 부쉈는지)
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
void solve(){
    queue<pair<int, int> > q;
    memset(visited, -1, sizeof(visited)); // WA: 벽을 하나도 부수지 않는 경우도 있으므로 -1로 초기화
    q.push(MP(0, 0));
    visited[0][0] = 0;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=n) continue;
            if(map[ni][nj]){
                // 흰 방인 경우 새 좌표에 기록된 부순 벽 개수보다 현재 좌표의 개수가 더 적은 경우 갱신
                if(visited[ni][nj]==-1 || visited[ni][nj]>visited[i][j]){
                    visited[ni][nj] = visited[i][j];
                    q.push(MP(ni, nj));
                }
            }
            else{
                // 검은 방인 경우 벽 하나 더 부순 값과 비교해서 갱신
                if(visited[ni][nj]==-1 || visited[ni][nj]>visited[i][j]+1){
                    visited[ni][nj] = visited[i][j]+1;
                    q.push(MP(ni, nj));
                }
            }
        }
    }
    cout << visited[n-1][n-1];
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            scanf("%1d", &map[i][j]);
        }
    }
    solve();
    return 0;
}