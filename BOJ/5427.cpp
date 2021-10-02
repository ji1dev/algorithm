// 5427번_불
#include <iostream>
#include <queue>
#include <memory.h>
#define MP make_pair
using namespace std;
int t, w, h, di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
int visited[1001][1001];
char map[1001][1001];
queue< pair<int, int> > fq, mq;
void bfs(){
    while(!mq.empty()){ // 상근이 이동 가능한 케이스가 있는 동안 계속 진행
        int fire = fq.size();
        while(fire--){
            int i = fq.front().first;
            int j = fq.front().second;
            fq.pop();
            for(int k=0; k<4; ++k){
                int ni = i+di[k];
                int nj = j+dj[k];
                if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
                if(map[ni][nj] == '.'){
                    map[ni][nj] = '*'; // 빈칸으로 불 퍼져나감
                    fq.push(MP(ni, nj));
                }
            }
        }
        int man = mq.size();
        while(man--){
            int i = mq.front().first;
            int j = mq.front().second;
            mq.pop();
            // 맵 가장자리 칸에 도달하면 다음 턴에 탈출 가능
            if(i==0 || i==h-1 || j==0 || j==w-1){
                cout << visited[i][j]+1 << "\n";
                return;
            }
            for(int k=0; k<4; ++k){
                int ni = i+di[k];
                int nj = j+dj[k];
                if(ni<0 || ni>=h || nj<0 || nj>=w || visited[ni][nj]!=-1) continue;
                if(map[ni][nj]=='.'){
                    visited[ni][nj] = visited[i][j]+1;
                    mq.push(MP(ni, nj));
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n"; // 탈출 불가능한 경우
}
int main(){
    cin >> t;
    for(int x=0; x<t; ++x){
        memset(visited, -1, sizeof(visited));
        cin >> w >> h;
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                scanf("%1s", &map[i][j]);
                if(map[i][j] == '*'){ // 불 위치
                    fq.push(MP(i, j));
                }
                if(map[i][j] == '@'){ // 상근이 위치
                    mq.push(MP(i, j));
                    visited[i][j]++;
                }
            }
        }
        bfs();
        while(!fq.empty()) fq.pop();
        while(!mq.empty()) mq.pop();
    }
    return 0;
}