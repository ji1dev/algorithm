// 14499번_주사위 굴리기
#include <iostream>
using namespace std;
int n, m, x, y, k, cmd;
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0}; // 동, 서, 북, 남
int map[21][21], dice[6]; // 아래는 주사위의 전개도 (0:윗 면, 2:동쪽을 바라보는 면, 5: 밑 면)
//   1
// 3 0 2
//   4
//   5
void Rolling(int direction){
    int tmp[6];
    for(int i=0; i<6; ++i) tmp[i] = dice[i];
    switch(direction){ // 각 방향으로 주사위를 굴림
        case 1: // 동쪽
            dice[0] = tmp[3];
            dice[3] = tmp[5];
            dice[5] = tmp[2];
            dice[2] = tmp[0];
            break;
        case 2: // 서쪽
            dice[0] = tmp[2];
            dice[2] = tmp[5];
            dice[5] = tmp[3];
            dice[3] = tmp[0];
            break;
        case 3: // 북쪽
            dice[0] = tmp[4];
            dice[4] = tmp[5];
            dice[5] = tmp[1];
            dice[1] = tmp[0];
            break;
        case 4: // 남쪽
            dice[0] = tmp[1];
            dice[1] = tmp[5];
            dice[5] = tmp[4];
            dice[4] = tmp[0];
            break;
    }
}
void Update(){
    // 이동한 칸에 쓰여 있는 수가 0이면, 주사위 바닥면에 쓰여 있는 수를 칸에 복사
    if(map[x][y] == 0){
        map[x][y] = dice[5];
    }
    // 0이 아닌 경우 칸에 쓰여 있는 수를 주사위 바닥면에 복사, 칸에 쓰인 수는 0이 됨
    else{
        dice[5] = map[x][y];
        map[x][y] = 0;
    }
}
int main(){
    cin >> n >> m >> x >> y >> k;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<k; ++i){
        cin >> cmd;
        int nx = x+dx[cmd-1]; // 이동 명령에 따라 주사위 좌표 계산
        int ny = y+dy[cmd-1];
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue; // 지도 바깥으로 나가는 명령은 무시
        Rolling(cmd); // 주사위를 굴림
        x = nx; // 주사위의 좌표 갱신
        y = ny;
        Update(); // 주사위 밑면의 값 또는 지도의 값 갱신
        cout << dice[0] << "\n"; // 주사위 윗 면의 값 출력
    }
    return 0;
}