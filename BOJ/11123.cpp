// 11123번_양 한마리... 양 두마리...
#include <iostream>
#include <queue>
#include <memory.h>
#define MP make_pair
#define MAX 101
using namespace std;
int h, w, t, di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
char map[MAX][MAX];
bool visited[MAX][MAX];
void solve(int si, int sj){
    queue<pair<int, int> > q;
    q.push(MP(si, sj));
    visited[si][sj] = true;
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k], nj = j+dj[k];
            if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
            if(visited[ni][nj] || map[ni][nj]=='.') continue;
            visited[ni][nj] = true;
            q.push(MP(ni, nj));
        }
    }
}
int main(){
    cin >> t;
    while(t--){
        int cnt = 0;
        cin >> h >> w;
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                cin >> map[i][j];
            }
        }
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                if(visited[i][j] || map[i][j]=='.') continue;
                solve(i, j); // (i, j)에서 시작되는 양 무리 확인
                cnt++;
            }
        }
        cout << cnt << "\n";
        memset(visited, false, sizeof(visited));
    }
    return 0;
}