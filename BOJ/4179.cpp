// 4179번_불!
#include <iostream>
#include <queue>
#define MAX 1001
#define MP make_pair
using namespace std;
queue<pair<int, int> > jq, fq;
char map[MAX][MAX];
int r, c, visited[MAX][MAX];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
void bfs(){
    while(!jq.empty()){ // 지훈이가 이동할 수 있는 경우가 존재하는동안 계속 확인
        int fsize = fq.size();
        while(fsize--){ // 불 확산
            int i = fq.front().first;
            int j = fq.front().second;
            fq.pop();
            for(int k=0; k<4; ++k){
                int ni = i+di[k], nj = j+dj[k];
                if(ni<0 || ni>=r || nj<0 || nj>=c) continue;
                if(map[ni][nj] != '.') continue;
                map[ni][nj] = 'F';
                fq.push(MP(ni, nj));
            }
        }
        int jsize = jq.size();
        while(jsize--){ // 지훈 이동
            int i = jq.front().first;
            int j = jq.front().second;
            jq.pop();
            if(i==0 || i==(r-1) || j==0 || j==(c-1)){ // 가장자리에 도달하면 다음 턴에 탈출 가능
                cout << visited[i][j];
                return;
            }
            for(int k=0; k<4; ++k){
                int ni = i+di[k], nj = j+dj[k];
                if(ni<0 || ni>=r || nj<0 || nj>=c || visited[ni][nj]) continue;
                if(map[ni][nj] != '.') continue;
                visited[ni][nj] = visited[i][j]+1;
                jq.push(MP(ni, nj));
            }
        }
    }
    cout << "IMPOSSIBLE";
}
int main(){
    cin >> r >> c;
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            cin >> map[i][j];
            if(map[i][j] == 'J'){
                jq.push(MP(i, j));
                visited[i][j] = 1;
            }
            else if(map[i][j] == 'F'){
                fq.push(MP(i, j));
            }
        }
    }
    bfs();
    return 0;
}