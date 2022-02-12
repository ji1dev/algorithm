// 14716번_현수막
#include <iostream>
#include <queue>
#define MP make_pair
#define MAX 251
using namespace std;
int n, m, cnt;
int di[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dj[] = {0, 0, -1, 1, -1, 1, -1, 1};
bool map[MAX][MAX], visited[MAX][MAX];
void solve(int si, int sj){
    queue<pair<int, int> > q;
    q.push(MP(si, sj));
    visited[si][sj] = true;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<8; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=m) continue;
            if(visited[ni][nj] || !map[ni][nj]) continue;
            visited[ni][nj] = true;
            q.push(MP(ni, nj));
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(visited[i][j] || !map[i][j]) continue;
            solve(i, j);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}