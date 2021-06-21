// 2636번_치즈
#include <iostream>
#include <queue>
#include <memory.h>
#define MP make_pair
using namespace std;
int n, m, elapsed, cheese, last, map[100][100];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
bool visited[100][100], isAir[100][100];
void findAir(){
    queue< pair<int, int> > q;
    memset(visited, false, sizeof(visited));
    memset(isAir, false, sizeof(isAir));
    q.push(MP(0, 0)); // 판의 가장자리에는 무조건 치즈가 없으므로 (0,0)부터 시작
    visited[0][0] = true;
    isAir[0][0] = true;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m ){
                // 아직 방문하지 않았고, 해당 좌표에 치즈가 없는 경우
                if(!visited[ni][nj] && !map[ni][nj]){
                    visited[ni][nj] = true;
                    isAir[ni][nj] = true;
                    q.push(MP(ni, nj));
                }
            }
        }
    }
}
void melt(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            // 치즈가 있는 칸에 인접한 4칸 중 하나라도 공기가 있으면,
            // 해당 칸의 치즈는 녹아 없어짐
            if(map[i][j]==1){
                for(int k=0; k<4; ++k){
                    int ni = i+di[k];
                    int nj = j+dj[k];
                    if(isAir[ni][nj]){
                        map[i][j] = 0;
                        cheese--; // 치즈 개수 감소
                        break;
                    }
                }
            }
        }
    }
    // 치즈가 남아있으면 개수를 저장 (모두 녹으면 갱신되지 않음)
    if(cheese) last = cheese;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j];
            if(map[i][j] == 1) cheese++;
        }
    }
    last = cheese; // 한 round만에 치즈가 모두 녹는 경우 고려
    // 치즈가 모두 녹아 없어질 때 까지 반복
    while(cheese != 0){
        findAir(); // 치즈가 없는 칸 중 공기가 있는 영역을 찾음
        melt(); // 공기와 접촉된 칸의 치즈를 녹임
        elapsed++;
    }
    cout << elapsed << "\n" << last;
    return 0;
}