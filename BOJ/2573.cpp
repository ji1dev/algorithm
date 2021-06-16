// 2573번_빙산
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int n, m, year, iceberg, map[300][300];
int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0}; // 동서남북
bool flag, visited[300][300];
void dfs(int i, int j){
    visited[i][j] = true;
    for(int k=0; k<4; ++k){
        int ni = i+di[k];
        int nj = j+dj[k];
        // 동서남북 좌표가 map범위내에 있고, 아직 방문하지 않았으며, 빙하가 존재하는 경우 탐색 진행
        if(ni>=0 && ni<n && nj>=0 && nj<m){
            if(!visited[ni][nj] && map[ni][nj]>0) dfs(ni, nj);        
        }
    }
}
void melt(){
    int zero_cnt = 0;
    int tmp[300][300] = {0, };
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(map[i][j] != 0){ // 빙하가 존재하는 좌표인 경우
                for(int k=0; k<4; ++k){ // 동서남북으로 0개수 확인하고 tmp배열에 저장
                    int ni = i+di[k];
                    int nj = j+dj[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && map[ni][nj]==0){
                        tmp[i][j]++;
                    } 
                }  
            }            
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            // 현재 좌표 인접 칸의 0개수만큼 빙하 녹이기, 음수로 내려가면 0으로 설정
            (map[i][j]-tmp[i][j] < 0) ? map[i][j]=0 : map[i][j]-=tmp[i][j];
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j];
        }
    }
    while(1){
        memset(visited, false, sizeof(visited)); // 매년마다 방문 기록 초기화
        flag = false;
        iceberg = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(!visited[i][j] && map[i][j]>0){
                    flag = true; // 하나라도 빙하가 존재하는 경우 활성화 되는 flag
                    dfs(i, j);
                    iceberg++;
                    // 빙하가 두개 이상으로 쪼개지면 걸린 시간을 출력하고 종료
                    if(iceberg > 1){
                        cout << year;
                        return 0;
                    }
                }
            }
        }
        // 현재 year에서 빙하를 찾지 못한 경우 (모두 녹은 경우) 0출력 후 종료
        if(!flag){
            cout << 0;
            break;
        }
        melt(); // 실제 빙하를 녹임
        year++; // year 증가
    }
    return 0;
}