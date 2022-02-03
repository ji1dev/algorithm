// 13565번_침투
#include <iostream>
#include <queue>
#define MP make_pair
#define MAX 1001
using namespace std;
int n, m, map[MAX][MAX];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
bool flag, visited[MAX][MAX];
queue<pair<int, int> > q;
void bfs(int sj){
    q.push(MP(0, sj));
    visited[0][sj] = true;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=m || visited[ni][nj]) continue;
            if(map[ni][nj]) continue;
            visited[ni][nj] = true;
            q.push(MP(ni, nj));
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            scanf("%1d", &map[i][j]);
        }
    }
    for(int j=0; j<m; ++j){
        if(!map[0][j]) bfs(j); // 바깥쪽에서 전류 통하는 칸 있으면 침투 시작
    }
    for(int j=0; j<m; ++j){
        if(visited[n-1][j]){ // 하나라도 안쪽까지 전달되면 침투 성공
            flag = true;
            break;
        }
    }
    cout << (flag ? "YES" : "NO");
    return 0;
}