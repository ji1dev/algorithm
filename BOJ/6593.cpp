// 6593번_상범 빌딩
#include <iostream>
#include <tuple>
#include <queue>
#include <memory.h>
#define MT make_tuple
using namespace std;
char map[31][31][31];
int l, r, c, visited[31][31][31];;
int di[] = {-1, 1, 0, 0, 0, 0};
int dj[] = {0, 0, -1, 1, 0, 0};
int dk[] = {0, 0, 0, 0, -1, 1};
queue<tuple<int, int, int> > q;
void bfs(){
    while(!q.empty()){
        int i = get<0>(q.front()); // layer
        int j = get<1>(q.front()); // row
        int k = get<2>(q.front()); // column
        q.pop(); 
        for(int d=0; d<6; ++d){
            int ni = i+di[d], nj = j+dj[d], nk = k+dk[d];
            if(map[ni][nj][nk] == 'E'){
                cout << "Escaped in " << visited[i][j][k] << " minute(s).\n";
                return;
            }
            if(ni<0 || ni>=l || nj<0 || nj>=r || nk<0 || nk>=c) continue; // map 범위 벗어남
            if(visited[ni][nj][nk] || map[ni][nj][nk]=='#') continue; // 이미 확인했거나 막힌 칸인 경우
            visited[ni][nj][nk] = visited[i][j][k]+1;
            q.push(MT(ni, nj, nk));
        }
    }
    cout << "Trapped!\n"; // 탐색중에 출구 못찾으면 trapped
}
int main(){
    while(1){
        cin >> l >> r >> c;
        if(!l && !r && !c) break;
        for(int i=0; i<l; ++i){
            for(int j=0; j<r; ++j){
                for(int k=0; k<c; ++k){
                    cin >> map[i][j][k];
                    if(map[i][j][k] == 'S'){
                        visited[i][j][k]++;
                        q.push(MT(i, j, k));
                    }
                }
            }
        }
        bfs();
        memset(visited, 0, sizeof(visited));
        memset(map, 0, sizeof(map));
        while(!q.empty()) q.pop();
    }
    return 0;
}