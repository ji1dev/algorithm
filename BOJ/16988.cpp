// 16988번_Baaaaaaaaaduk2 (Easy)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
#define MAX 21
#define MP make_pair
using namespace std;
bool visited[MAX][MAX];
int n, m, ans, map[MAX][MAX];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
vector<pair<int, int> > v; // 빈 칸 좌표 기록
int bfs(int si, int sj){
    int cnt = 1;
    queue<pair<int, int> > q;
    q.push(MP(si, sj));
    visited[si][sj] = true;
    bool flag = false;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=m || visited[ni][nj]) continue;
            if(map[ni][nj] == 0){
                // 빈틈이 존재한다고 즉시 리턴하면 같은 돌 그룹에서 탐색이 끊어짐
                // 다른 상대 돌 위치에서부터 이어서 탐색해도 이전 탐색의 방문여부 그대로 유지되므로
                // 특정 상황에서 같은 돌 그룹을 제대로 탐색하지 못하거나 빈틈이 있음에도 이를 파악하지 못하는 경우 발생
                // TC2의 경우 (4, 2), (4, 3)에 착수했을 때 위와같은 방법 사용시 인접한 빈틈이 없는 (4, 0)까지 쭉 넘어가고,
                // 방문여부는 그대로 유지되므로 (4, 1)만 큐에 들어가게되고 이후 추가로 조건을 만족하는 칸은 없음
                // 따라서 실제로는 빈틈이 존재하지만 이를 걸러내지 못하고 상대돌의 개수를 리턴함
                // 이를 해결하기 위해 빈틈을 찾았더라도 같은 돌 그룹의 탐색은 끝까지 이어가도록 함 
                flag = true;
                continue;
            }
            else if(map[ni][nj] == 1) continue; // 자신의 돌이면 넘어감
            visited[ni][nj] = true;
            q.push(MP(ni, nj));
            cnt++;            
        }
    }
    if(flag) return 0;
    return cnt;
}
void solve(){
    for(int p=0; p<v.size(); ++p){ // 빈 칸 두곳에 착수
        map[v[p].first][v[p].second] = 1;
        for(int q=p+1; q<v.size(); ++q){
            int cnt = 0;
            map[v[q].first][v[q].second] = 1;
            for(int i=0; i<n; ++i){ // 현 상태에서 죽일 수 있는 상대 돌 개수를 구함
                for(int j=0; j<m; ++j){
                    if(map[i][j]!=2 || visited[i][j]) continue;
                    cnt += bfs(i, j);
                }
            }
            ans = max(ans, cnt);
            map[v[q].first][v[q].second] = 0; // 원상복구
            memset(visited, false, sizeof(visited));
        }
        map[v[p].first][v[p].second] = 0;
    }
    cout << ans;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j];
            if(map[i][j] == 0) v.push_back(MP(i, j));
        }
    }
    solve();
    return 0;
}