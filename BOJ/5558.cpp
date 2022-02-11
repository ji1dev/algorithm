// 5558번_チーズ (Cheese)
#include <iostream>
#include <queue>
#define MP make_pair
#define MAX 1001
using namespace std;
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
int h, w, n, ans, visited[MAX][MAX][10];
char map[MAX][MAX];
queue<pair<int, int> > q;
int solve(int hp){
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(map[i][j]-'0' == hp){ // 목표 치즈에 도달한 경우
            while(!q.empty()) q.pop();
            q.push(MP(i, j)); // 다음 탐색의 시작점
            return visited[i][j][hp];
        }
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
            if(visited[ni][nj][hp] || map[ni][nj]=='X') continue;
            visited[ni][nj][hp] = visited[i][j][hp]+1;
            q.push(MP(ni, nj));
        }
    }
    return 0;
}
int main(){
    cin >> h >> w >> n; // 치즈공장 개수 n
    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            cin >> map[i][j];
            if(map[i][j] == 'S') q.push(MP(i, j)); // 최초 시작점
        }
    }
    // S->1, 1->2, ..., (n-1)->n 각각의 최단거리를 모두 더함
    // 목표 치즈까지의 거리를 구하므로 그 과정에서 체력보다 치즈의 경도가 강하면 자연스럽게 먹지 않고 지나감
    for(int i=1; i<=n; ++i){
        ans += solve(i);
    }
    cout << ans;
    return 0;
}