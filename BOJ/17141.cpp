// 17141번_연구소 2
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MP make_pair
#define INF 987654321
using namespace std;
int n, m, ans, map[51][51];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
bool visited[11];
vector< pair<int, int> > v, vs;
void spread(){
    queue< pair<int, int> > q;
    int vmap[51][51]; // 바이러스 퍼진 결과 배열
    memset(vmap, -1, sizeof(vmap));
    for(int i=0; i<vs.size(); ++i){
        vmap[vs[i].first][vs[i].second] = 0; // 바이러스 놓은 위치
        q.push(vs[i]);
    }
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=n || map[ni][nj]==1) continue;
            if(vmap[ni][nj] == -1){ // 퍼지지 않은 칸
                vmap[ni][nj] = vmap[i][j]+1; // 이전 칸 까지 퍼지는 시간+1
                q.push(MP(ni, nj));
            }
        }
    }
    int sec = -1;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(map[i][j]!=1 && vmap[i][j]==-1) return; // 벽 아닌데 바이러스 없으면 갱신 안함
            sec = max(sec, vmap[i][j]);
        }
    }
    ans = min(ans, sec); // 모든 빈 칸에 바이러스가 있게 되는 최소 시간 갱신 
}
void select(int cnt, int begin){
    if(cnt == m){
        spread();
        return;
    }
    for(int i=begin; i<v.size(); ++i){
        if(!visited[i]){
            visited[i] = true;
            vs.push_back(v[i]);
            select(cnt+1, i);
            visited[i] = false;
            vs.pop_back();
        }
    }
}
int main(){
    F_IO;
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> map[i][j];
            if(map[i][j] == 2) v.push_back(MP(i, j));
        }
    }
    ans = INF;
    select(0, 0); // 선택한 위치 수, 인덱스 
    if(ans != INF) cout << ans;
    else cout << -1;
    return 0;
}