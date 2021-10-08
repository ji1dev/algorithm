// 19236번_청소년 상어
#include <iostream>
#include <algorithm>
#include <memory.h>
#define MP make_pair
using namespace std;
int di[] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 북쪽부터 ccw
int dj[] = {0, -1, -1, -1, 0, 1, 1, 1};
int map[4][4], max_eat;
pair< pair<int, int>, int > fish[17]; // 물고기 좌표와 방향
void dfs(int si, int sj, int sd, int eat){
    // 물고기 정보, 칸 정보 복사
    int tmp[4][4];
    pair< pair<int, int>, int > ftmp[17];
    memcpy(tmp, map, sizeof(map));
    memcpy(ftmp, fish, sizeof(fish));

    // 물고기 이동
    for(int n=1; n<=16; ++n){
        int i = fish[n].first.first;
        int j = fish[n].first.second;
        int d = fish[n].second;
        if(d == -1) continue; // 이미 먹힌 물고기는 넘어감

        // 최대 8방향까지 확인하고도 이동할 수 있는 칸 없으면 이동 x
        for(int k=0; k<8; ++k){
            int ni = i+di[d];
            int nj = j+dj[d];
            int adj_n = map[ni][nj];

            // 경계 넘거나 상어 있는 칸이면 이동 가능할 때 까지 물고기의 방향 회전
            if(ni<0 || ni>=4 || nj<0 || nj>=4 || adj_n==99){
                d = (d+1)%8;
                continue;
            }
                       
            map[ni][nj] = n; // n번 물고기와 adj_n번 물고기 위치 교환
            fish[n] = MP(MP(ni, nj), d);
            map[i][j] = adj_n;
            fish[adj_n].first.first = i;
            fish[adj_n].first.second = j;
            break; // 물고기는 한 칸만 이동 가능
        }
    }

    // 상어 이동
    int ni = si;
    int nj = sj;
    while(1){
        ni += di[sd]; // 이전에 먹은 물고기의 방향 따라 이동
        nj += dj[sd];
        int adj_n = map[ni][nj];
        
        if(ni<0 || ni>=4 || nj<0 || nj>=4) break; // 경계 넘으면 이동할 수 없으므로 집으로 감 
        if(adj_n == 0) continue; // 물고기가 없는 칸이면 같은 방향으로 계속 이동

        int adj_d = fish[adj_n].second; // 인접 칸에 있는 물고기의 방향
        map[ni][nj] = 99; // 물고기 먹고 그 위치에 상어 올림
        fish[adj_n].second = -1; // 먹힌 물고기는 방향 -1
        map[si][sj] = 0; // 상어가 있던 자리 빈 칸으로 표시

        dfs(ni, nj, adj_d, eat+adj_n);

        map[ni][nj] = adj_n; // 상어 이동 이전 상태로 복원
        fish[adj_n].second = adj_d;
        map[si][sj] = 99;
    }

    // 먹은 물고기 최댓값 갱신
    max_eat = max(max_eat, eat);

    // 물고기 정보, 칸 정보 복원
    memcpy(map, tmp, sizeof(map));
    memcpy(fish, ftmp, sizeof(fish));
}
int main(){
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            int a, b;
            cin >> a >> b;
            fish[a] = MP(MP(i, j), b-1); // a 물고기의 좌표와 방향 b-1 (0을 북쪽으로 잡고 ccw)
            map[i][j] = a; // a 물고기의 위치
        }
    }
    int fnum = map[0][0];
    int fdir = fish[fnum].second;
    map[0][0] = 99; // 물고기 먹고 그 위치에 상어 올림
    fish[fnum].second = -1; // 먹힌 물고기는 방향 -1로 표시
    dfs(0, 0, fdir, fnum); // 상어 좌표, 방향, 먹은 물고기 값
    cout << max_eat;
    return 0;
}