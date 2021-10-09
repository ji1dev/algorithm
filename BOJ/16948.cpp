// 16948번_데스 나이트
#include <iostream>
#include <queue>
#define INF 987654321
#define MP make_pair
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int di[] = {-2, -2, 0, 0, 2, 2};
int dj[] = {-1, 1, -2, 2, -1, 1};
int n, min_mv, map[201][201];
bool visited[201][201];
pair<int, int> loc[2];
void bfs(){
    queue< pair< pair<int, int>, int > > q; // 좌표, 이동횟수
    q.push(MP(loc[0], 0));
    visited[loc[0].first][loc[0].second] = true;
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(i==loc[1].first && j==loc[1].second){
            min_mv = cnt;
            return;
        }
        for(int k=0; k<6; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=n) continue;
            if(!visited[ni][nj]){
                q.push(MP(MP(ni, nj), cnt+1));
                visited[ni][nj] = true;
            }
        }
    }
}
int main(){
    F_IO;
    cin >> n;
    for(int i=0; i<2; ++i){ // 출발, 도착 좌표
        int r, c;
        cin >> r >> c;
        loc[i] = MP(r, c);
    }
    min_mv = INF;
    bfs();
    if(min_mv == INF) cout << -1;
    else cout << min_mv;
    return 0;
}