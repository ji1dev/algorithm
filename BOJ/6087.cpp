// 6087번_레이저 통신
#include <iostream>
#include <queue>
#define MP make_pair
#define INF 987654321
using namespace std;
int w, h, visited[101][101]; // 특정 좌표 도달시까지 필요한 최소 거울 개수 저장
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1}; // 상, 하, 좌, 우
char map[101][101];
pair<int, int> src, dst;
queue< pair< pair<int, int>, pair<int, int> > > q;
void bfs(){
    // 좌표와 필요한 거울의 개수, 진행 방향(0~3: 상하좌우, -1: 시작 칸)
    q.push(MP(MP(src.first, src.second), MP(0, -1)));
    visited[src.first][src.second] = 0;
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int m = q.front().second.first; // 거울 개수
        int d = q.front().second.second; // 진행 방향
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            int nm = m;
            if(ni<0 || ni>=h || nj<0 || nj>=w || map[ni][nj]=='*') continue;
            if(d!=k && d!=-1) nm++; // 진행 방향과 다른 방향으로 꺾는 경우 거울 개수++ (시작 칸 제외)
            // (ni, nj)도달까지 필요한 기존의 거울 개수와 같거나 더 적은 개수를 사용하여 도달 가능한 경우 갱신
            // 현재 좌표에서 거울 개수가 같더라도 목적지 도달 전까지는 여러 경우의 수가 나올 수 있으므로 같은 경우도 포함
            if(nm <= visited[ni][nj]){
                q.push(MP(MP(ni, nj), MP(nm, k)));
                visited[ni][nj] = nm;
            }
        }
    }
}
int main(){
    bool first = true;
    cin >> w >> h;
    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            cin >> map[i][j];
            visited[i][j] = INF;
            if(map[i][j] == 'C'){ // 레이저로 연결해야 하는 칸을 따로 저장해둠
                if(first){
                    src.first = i;
                    src.second = j;
                    first = false;
                }
                else{
                    dst.first = i;
                    dst.second = j;
                }
            }
        }
    }
    bfs();
    cout << visited[dst.first][dst.second];
    return 0;
}