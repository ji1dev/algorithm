// 14503번_로봇청소기
#include <iostream>
using namespace std;
int n, m, r, c, d, cnt;
int map[50][50];
int dr[] = {-1, 0, 1, 0}; // top, right, bottom, left
int dc[] = {0, 1, 0, -1};
void clean(){
    map[r][c] = 9; // 현재 위치를 청소함
    cnt++; // 청소한 칸의 개수 증가
}
bool turnLeft(){
    // d=0 -> 3, d=1 -> 0, d=2 -> 1, d=3 -> 2
    bool isWall = false; // 뒤쪽 방향이 벽이면 활성화
    while(!isWall){
        // 네 방향 모두 확인 (2-b)
        for(int i=0; i<4; ++i){
            d = (d-1>=0)?(d-1):3;
            if(map[r+dr[d]][c+dc[d]] == 0){
                r += dr[d];
                c += dc[d];
                return true; // 청소 가능한 경우 true return (2-a)
            }
        }
        // 뒤쪽 방향이 벽이라 후진할 수 없는 경우 loop 탈출, false return (2-d)
        if(map[r-dr[d]][c-dc[d]] == 1){
            isWall = true;
        }
        // 네 방향 모두 청소 되어 있거나 벽인 경우 d유지하고 한 칸 후진 (2-c)
        else{
            r -= dr[d];
            c -= dc[d];
        }
    }
    return false; // 더 이상 청소 불가능한 경우
}
int main(){
    cin >> n >> m;
    cin >> r >> c >> d; // d는 0~3 (top, right, bottom, left 순서)
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j];
        }
    }
    clean();
    while(1){
        if(turnLeft()) clean(); // 왼쪽 방향에 아직 청소하지 않은 공간 존재하면 회전, 전진, 청소
        else break; // 더 이상 청소할 수 없는 조건이면 loop탈출, cnt 출력
    }
    cout << cnt;
    return 0;
}