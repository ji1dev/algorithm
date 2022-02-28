// 14497번_주난의 난
#include <iostream>
#include <queue>
#define MAX 301
#define MP make_pair
using namespace std;
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
int jmp, n, m, si, sj, x;
char map[MAX][MAX];
bool visited[MAX][MAX];
bool solve(){
    queue<pair<int, int> > q;
    q.push(MP(si-1, sj-1));
    visited[si-1][sj-1] = true;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=m || visited[ni][nj]) continue;
            if(map[ni][nj] == '#') return true; // 범인 발견
            visited[ni][nj] = true;
            if(map[ni][nj] == '1') map[ni][nj] = '0'; // 파동 맞고 쓰러짐
            else q.push(MP(ni, nj)); // 파동이 계속 퍼질 수 있는 경우
        }
    }
    return false;
}
int main(){
    cin >> n >> m;
    cin >> si >> sj >> x >> x;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            scanf("%1s", &map[i][j]);
        }
    }
    while(1){
        jmp++;
        if(solve()) break;
        memset(visited, false, sizeof(visited));
    }
    cout << jmp;
    return 0;
}