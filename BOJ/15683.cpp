// 15683번_감시
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#define INF 987654321
#define MP make_pair
using namespace std;
vector< pair<int, int> > cctv; // cctv 좌표
int n, m, blind, map[9][9], tmp[9][9], cctv_way[9]; // cctv 방향
int di[] = {0, 1, 0, -1}; // 오른쪽부터 시계방향
int dj[] = {1, 0, -1, 0};
int getBlind(){
    int cnt = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(tmp[i][j] == 0) cnt++;
        }
    }
    return cnt;
}
void Watch(int i, int j, int way){
    // cctv의 방향에 따라 지도에 감시 영역 표시
    int ni = i;
    int nj = j;
    // 범위 벗어나지 않고, 벽 만나기 전까지 빈 칸은 감시 가능한 영역으로 표시
    while(ni>=0 && ni<n && nj>=0 && nj<m && tmp[ni][nj]!=6){
        if(tmp[ni][nj] == 0) tmp[ni][nj] = -1;
        ni += di[way]; // 같은 방향으로 계속 이동
        nj += dj[way];
    }    
}
void runCCTV(){
    // cctv의 타입과 방향 조합에 따라 감시 시작 
    memcpy(tmp, map, sizeof(map));
    for(int l=0; l<cctv.size(); ++l){
        int i = cctv[l].first;
        int j = cctv[l].second;
        int way = cctv_way[l]; // l번째 cctv가 가리킬 수 있는 방향 조합의 번호
        switch(tmp[i][j]){ // cctv의 타입
            case 1:
                Watch(i, j, way); // 우측부터 시계방향 하나씩
                break;
            case 2:
                Watch(i, j, way+2); // (좌,우) 또는 (상,하)
                Watch(i, j, way);
                break;
            case 3:
                Watch(i, j, (way+3)%4); // (상,우), (우,하), (하,좌), (좌,상)
                Watch(i, j, way);
                break;
            case 4:
                Watch(i, j, (way+2)%4); // (좌,상,우), (상,우,하), (우,하,좌), (하,좌,상)
                Watch(i, j, (way+3)%4);
                Watch(i, j, way);
                break;
            case 5:
                Watch(i, j, 0); // 우측부터 시계방향 모두
                Watch(i, j, 1);
                Watch(i, j, 2);
                Watch(i, j, 3);
                break;
        }
    }
}
void setCCTV(int cnt){
    if(cnt == cctv.size()){
        // 모든 cctv의 방향 조합이 정해지면 감시 시작, 사각지대의 최소 크기 갱신
        runCCTV();
        blind = min(blind, getBlind());
        return;
    }
    int i = cctv[cnt].first;
    int j = cctv[cnt].second;
    for(int k=0; k<4; ++k){
        // cctv의 타입에 따라 1~4가지 방향을 설정할 수 있음
        if(map[i][j]==2 && k>=2) continue; // 2번은 상하, 좌우 2way
        if(map[i][j]==5 && k>=1) continue; // 3번은 상하좌우 1way
        cctv_way[cnt] = k;
        setCCTV(cnt+1);
        cctv_way[cnt] = 0;
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j];
            if(map[i][j]>=1 && map[i][j]<=5){
                cctv.push_back(MP(i, j));
            }
        }
    }
    blind = INF;
    setCCTV(0); // 각 cctv가 감시할 수 있는 방향의 조합을 설정
    cout << blind;
    return 0;
}