// 13460번_구슬 탈출 2
#include <iostream>
#include <queue>
#define MP make_pair
using namespace std;
pair<int, int> rs, bs;
int n, m, di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
char map[11][11];
bool visited[11][11][11][11]; // 빨간 구슬, 파란 구슬 각각 방문 여부 기록 
queue< pair< pair< pair<int, int>, pair<int, int> > ,int > > q; // 빨간 구슬, 파란 구슬, 기울이는 동작 횟수
int Roll(int &i, int &j, int k){
    int cnt = 0;
    // 벽을 만나거나 구멍에 빠지기 전까지 계속 이동
    while(map[i+di[k]][j+dj[k]]!='#' && map[i][j]!='O'){
        i += di[k];
        j += dj[k];
        cnt++;
    }
    return cnt; // 현재 구슬이 이동한 칸의 수
}
void bfs(){
    q.push(MP(MP(MP(rs.first, rs.second), MP(bs.first, bs.second)), 0));
    visited[rs.first][rs.second][bs.first][bs.second] = true;
    while(!q.empty()){
        int ri = q.front().first.first.first;
        int rj = q.front().first.first.second;
        int bi = q.front().first.second.first;
        int bj = q.front().first.second.second;
        int cnt = q.front().second;
        //printf("(%d,%d), (%d,%d), cnt=%d\n", ri, rj, bi, bj, cnt);
        q.pop();
        if(cnt > 10) break; // 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없는 경우
        if(map[ri][rj] == 'O'){ // 빨간 구슬의 위치가 구멍인 경우
            cout << cnt;
            return;
        }
        for(int k=0; k<4; ++k){
            int nri = ri, nrj = rj, nbi = bi, nbj = bj, r_cnt, b_cnt;
            r_cnt = Roll(nri, nrj, k); // k방향으로 기울여서 구슬 굴리기
            b_cnt = Roll(nbi, nbj, k);
            if(map[nbi][nbj] == 'O') continue; // 파란 구슬이 빠지면 실패이므로 건너뜀
            // 더 많이 이동한 구슬은 현재 기울인 방향과 반대쪽으로 더 멀리 있었다는 의미
            // 따라서 두 구슬의 위치가 겹치는 경우 더 많이 이동한 구슬을 한 칸 롤백
            if(nri==nbi && nrj==nbj) { 
                if(r_cnt > b_cnt){
                    nri -= di[k];
                    nrj -= dj[k];
                }
                else{
                    nbi -= di[k];
                    nbj -= dj[k];
                }
            }
            //printf("k: %d / (%d,%d), (%d,%d)\n", k, nri, nrj, nbi, nbj);
            if(visited[nri][nrj][nbi][nbj]) continue;
            q.push(MP(MP(MP(nri, nrj), MP(nbi, nbj)), cnt+1));
            visited[nri][nrj][nbi][nbj] = true;
        }
    }
    cout << -1;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            scanf("%1s", &map[i][j]);
            if(map[i][j] == 'R') rs = MP(i, j);
            else if(map[i][j] == 'B') bs = MP(i, j);
        }
    }
    bfs();
    return 0;
}