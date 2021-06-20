// 14502번_연구소
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define MP make_pair
using namespace std;
int n, m, maxSafeArea, map[8][8], tmp[8][8];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1}; // 상, 하, 좌, 우
void bfs(){
    int safeArea = 0;
    int virus[8][8]; // 바이러스 퍼진 결과 저장할 배열
    queue< pair<int, int> > q;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){   
            if(tmp[i][j] == 2){
                q.push(MP(i, j)); // 바이러스 좌표 큐에 push
            }
        }
    }
    memcpy(virus, tmp, sizeof(tmp));
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m){ // 연구소 범위 내에 들어오는 경우
                if(virus[ni][nj] == 0){ // 해당 좌표의 값이 벽, 바이러스가 아닌 경우
                    virus[ni][nj] = 2;
                    q.push(MP(ni, nj));
                }
            }
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            // 안전 영역 count
            if(virus[i][j] == 0) safeArea++;
        }
    }
    maxSafeArea = max(maxSafeArea, safeArea); // 안전 영역 최댓값 갱신
}
void setWall(int cnt){
    // 벽 3개 세우면 bfs로 바이러스 퍼트리고 안전 영역 개수 count
    if(cnt == 3){
        bfs(); 
        return;
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){   
            if(tmp[i][j] == 0){
                tmp[i][j] = 1;
                setWall(cnt+1); // 재귀함수로 나머지 벽을 마저 세움
                tmp[i][j] = 0;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j]; // 연구소 상태 원본
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            // 빈 칸 발견시 연구소 상태를 임시 배열에 복사해서 사용함
            if(map[i][j] == 0){
                memcpy(tmp, map, sizeof(map)); 
                tmp[i][j] = 1; // 해당 칸에 벽을 세움
                setWall(1); // 재귀함수로 나머지 벽 2개를 마저 세움
                tmp[i][j] = 0; // 벽을 제거
            }
        }
    }
    cout << maxSafeArea;
    return 0;
}