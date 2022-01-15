// 2638번_치즈
#include <iostream>
#include <queue>
#define MAX 101
#define MP make_pair
using namespace std;
bool map[MAX][MAX];
int n, m, cheese, elapsed;
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
void solve(){
    queue<pair<int, int> > q;
    bool visited[MAX][MAX] = {false, };
    q.push(MP(0, 0));
    visited[0][0] = true;
    while(!q.empty()){ // 외부 공기가 있는 위치를 기록
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k], nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=m) continue;
            if(visited[ni][nj] || map[ni][nj]) continue;
            visited[ni][nj] = true;
            q.push(MP(ni, nj));
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(!map[i][j]) continue;
            int cnt = 0;
            for(int k=0; k<4; ++k){
                int ni = i+di[k], nj = j+dj[k];
                if(visited[ni][nj]) cnt++;
                if(cnt >= 2){ // 2면이상 공기와 접촉한 치즈는 녹아내림
                    map[i][j] = 0;
                    cheese--;
                    break;
                }
            }
        }
    }
    elapsed++;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j];
            if(map[i][j]) cheese++;
        }
    }
    while(cheese) solve();
    cout << elapsed;
    return 0;
}