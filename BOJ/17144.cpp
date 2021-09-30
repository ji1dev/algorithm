// 11744번_미세먼지 안녕!
#include <iostream>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int r, c, t, dust, map[51][51];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
int top, bottom; // 공기청정기 상-하부 행
void spread(){
    int tmp[51][51] = {0, };
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            // 미세먼지 없거나 공기청정기가 위치한 칸은 넘어감
            if(map[i][j]==0 || map[i][j]==-1) continue;
            int cnt = 0;
            int amount = map[i][j]/5; // 확산되는 미세먼지 양
            for(int k=0; k<4; ++k){
                int ni = i+di[k];
                int nj = j+dj[k];
                // 인접한 방향에 공기청정기 있거나, 칸이 없으면 넘어감
                if(map[ni][nj]==-1 || ni<0 || ni>=r || nj<0 || nj>=c) continue;
                tmp[ni][nj] += amount;
                cnt++; // 확산 방향 증가
            }
            tmp[i][j] -= amount*cnt; // 남은 미세먼지의 양 계산
        }
    }
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            map[i][j] += tmp[i][j]; // 확산 결과 반영
        }
    }
}
void purify(){
    dust -= map[top-1][0]; // 공기청정기 바로 위, 아래칸의 먼지는 정화됨
    dust -= map[bottom+1][0];
    // 반시계 방향 돌리기
    for (int i=top-1; i>0; --i) map[i][0] = map[i-1][0]; // left
    for (int j=0; j<c-1; ++j) map[0][j] = map[0][j+1]; // top
    for (int i=0; i<top; ++i) map[i][c-1] = map[i+1][c-1]; // right
    for (int j=c-1; j>1; --j) map[top][j] = map[top][j-1]; // bottom
    map[top][1] = 0; // 공기청정기에서 나오는 바람은 미세먼지 x
    
    // 시계 방향 돌리기
    for (int i=bottom+1; i<r-1; ++i) map[i][0] = map[i+1][0]; // left
    for (int j=0; j<c-1; ++j) map[r-1][j] = map[r-1][j+1]; // bottom    
    for (int i=r-1; i>bottom; --i) map[i][c-1] = map[i-1][c-1]; // right
    for (int j=c-1; j>0; --j) map[bottom][j] = map[bottom][j-1]; // top
    map[bottom][1] = 0;
}
int main(){
    F_IO;
    bool flag = false;
    cin >> r >> c >> t;
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            cin >> map[i][j];
            if(map[i][j] == -1){
                if(!flag){
                    top = i;
                    flag = true;
                }
                else bottom = i;
            }
            else dust += map[i][j]; // 미세먼지 총량
        }
    }
    while(t--){ // t초동안 미세먼지 확산, 공기청정기 돌림
        spread();
        purify();
    }
    cout << dust;
    return 0;
}