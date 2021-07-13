// 3055번_탈출
#include <iostream>
#include <queue>
#include <algorithm>
#define MP make_pair
using namespace std;
int r, c, ti, tj, visited[51][51];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
char map[51][51];
queue< pair<int, int> > sq, wq;
void bfs(){
    while(!sq.empty()){
        // 1. 인접한 빈 칸으로 물 확장
        int wq_size = wq.size();
        while(wq_size--){ // 현재 큐에 들어있는 모든 물의 위치에서 확장시킴
            int wi = wq.front().first;
            int wj = wq.front().second;
            wq.pop();
            for(int k=0; k<4; ++k){
                int nwi = wi+di[k];
                int nwj = wj+dj[k];
                if(nwi<0 || nwi>=r || nwj<0 || nwj>=c) continue;
                // 빈 칸인 경우
                if(map[nwi][nwj] == '.'){ 
                    map[nwi][nwj] = '*'; // 물 확장
                    wq.push(MP(nwi, nwj));
                }
            }
        }
        // 2. 고슴도치 이동
        int sq_size = sq.size();
        while(sq_size--){ // 현재 큐에 들어있는 모든 고슴도치의 위치에서 이동시킴
            int si = sq.front().first;
            int sj = sq.front().second;
            sq.pop();
            // 고슴도치가 비버 굴 도착한 경우
            if(si==ti && sj==tj){
                cout << visited[si][sj]-1;
                return;
            }
            for(int k=0; k<4; ++k){
                int nsi = si+di[k];
                int nsj = sj+dj[k];
                if(nsi<0 || nsi>=r || nsj<0 || nsj>=c) continue;
                // 아직 고슴도치가 방문하지 않은 칸이고, 빈 칸이거나 비버 굴인 경우
                if(visited[nsi][nsj]==0 && (map[nsi][nsj]=='.' || map[nsi][nsj]=='D')){
                    visited[nsi][nsj] = visited[si][sj]+1; // 이동 시간 증가
                    sq.push(MP(nsi, nsj));
                }   
            }
        }
    }
    // 고슴도치를 이동시킬 수 있는 모든 경우를 시도해봤지만 비버 굴에 도착하지 못한 경우
    cout << "KAKTUS"; 
}
int main(){
    cin >> r >> c;
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            scanf("%1s", &map[i][j]);
            if(map[i][j] == '*') wq.push(MP(i, j)); // 물 위치 
            if(map[i][j] == 'S'){
                sq.push(MP(i, j)); // 고슴도치 위치
                visited[i][j]++;
            }
            if(map[i][j] == 'D'){
                ti = i; // 비버 굴 위치
                tj = j;
            }   
        }
    }
    bfs();
    return 0;
}