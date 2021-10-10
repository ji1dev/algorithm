// 16939번_2x2x2 큐브
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
// 큐브 전개도 (면 번호)
//   0
// 3 1 4 5
//   2
vector<int> cube[6];
bool rotate(int side, int dir){
    int c0, c1, c2, c3;
    vector<int> rcube[6];
    for(int i=0; i<6; ++i) rcube[i] = cube[i];
    if(dir == 0){ // ccw
        if(side == 0){ // 면 0
            c0 = rcube[1][0];
            c1 = rcube[1][1];
            rcube[1][0] = rcube[3][0];
            rcube[1][1] = rcube[3][1];
            rcube[3][0] = rcube[5][0];
            rcube[3][1] = rcube[5][1];
            rcube[5][0] = rcube[4][0];
            rcube[5][1] = rcube[4][1];
            rcube[4][0] = c0;
            rcube[4][1] = c1;
        }
        else if(side == 1){ // 면 1
            c2 = rcube[0][2];
            c3 = rcube[0][3];
            rcube[0][2] = rcube[4][0];
            rcube[0][3] = rcube[4][2];
            rcube[4][0] = rcube[2][1];
            rcube[4][2] = rcube[2][0];
            rcube[2][1] = rcube[3][3];
            rcube[2][0] = rcube[3][1];
            rcube[3][3] = c3;
            rcube[3][1] = c1;
        }
        else if(side == 2){ // 면 2
            c2 = rcube[1][2];
            c3 = rcube[1][3];
            rcube[1][2] = rcube[4][2];
            rcube[1][3] = rcube[4][3];
            rcube[4][2] = rcube[5][2];
            rcube[4][3] = rcube[5][3];
            rcube[5][2] = rcube[3][2];
            rcube[5][3] = rcube[3][3];
            rcube[3][2] = c2;
            rcube[3][3] = c3;
        }
        else if(side == 3){ // 면 3
            c0 = rcube[0][0];
            c2 = rcube[0][2];
            rcube[0][0] = rcube[1][0];
            rcube[0][2] = rcube[1][2];
            rcube[1][0] = rcube[2][0];
            rcube[1][2] = rcube[2][2];
            rcube[2][0] = rcube[5][3];
            rcube[2][2] = rcube[5][1];
            rcube[5][0] = c0;
            rcube[5][2] = c2;
        }
        else if(side == 4){ // 면 4
            c3 = rcube[0][3];
            c1 = rcube[0][1];
            rcube[0][3] = rcube[5][0];
            rcube[0][1] = rcube[5][2];
            rcube[5][0] = rcube[2][3];
            rcube[5][2] = rcube[2][1];
            rcube[2][3] = rcube[1][3];
            rcube[2][1] = rcube[1][1];
            rcube[1][3] = c3;
            rcube[1][1] = c1;
        }
        else if(side == 5){ // 면 5
            c1 = rcube[0][1];
            c0 = rcube[0][1];
            rcube[0][1] = rcube[3][0];
            rcube[0][0] = rcube[3][2];
            rcube[3][0] = rcube[2][2];
            rcube[3][2] = rcube[2][3];
            rcube[2][2] = rcube[4][3];
            rcube[2][3] = rcube[4][1];
            rcube[4][3] = c1;
            rcube[4][1] = c0;
        }
    }
    else{ // cw
        if(side == 0){ // 면 0
            c0 = rcube[1][0];
            c1 = rcube[1][1];
            rcube[1][0] = rcube[4][0];
            rcube[1][1] = rcube[4][1];
            rcube[4][0] = rcube[5][0];
            rcube[4][1] = rcube[5][1];
            rcube[5][0] = rcube[3][0];
            rcube[5][1] = rcube[3][1];
            rcube[3][0] = c0;
            rcube[3][1] = c1;
        }
        else if(side == 1){ // 면 1
            c2 = rcube[0][2];
            c3 = rcube[0][3];
            rcube[0][2] = rcube[3][3];
            rcube[0][3] = rcube[3][1];
            rcube[3][3] = rcube[2][1];
            rcube[3][1] = rcube[2][0];
            rcube[2][1] = rcube[4][0];
            rcube[2][0] = rcube[4][2];
            rcube[4][0] = c3;
            rcube[4][2] = c1;
        }
        else if(side == 2){ // 면 2
            c2 = rcube[1][2];
            c3 = rcube[1][3];
            rcube[1][2] = rcube[3][2];
            rcube[1][3] = rcube[3][3];
            rcube[3][2] = rcube[5][2];
            rcube[3][3] = rcube[5][3];
            rcube[5][2] = rcube[4][2];
            rcube[5][3] = rcube[4][3];
            rcube[4][2] = c2;
            rcube[4][3] = c3;
        }
        else if(side == 3){ // 면 3
            c0 = rcube[0][0];
            c2 = rcube[0][2];
            rcube[0][0] = rcube[5][3];
            rcube[0][2] = rcube[5][1];
            rcube[5][3] = rcube[2][0];
            rcube[5][1] = rcube[2][2];
            rcube[2][0] = rcube[1][0];
            rcube[2][2] = rcube[1][2];
            rcube[1][0] = c0;
            rcube[1][2] = c2;
        }
        else if(side == 4){ // 면 4
            c3 = rcube[0][3];
            c1 = rcube[0][1];
            rcube[0][3] = rcube[1][3];
            rcube[0][1] = rcube[1][1];
            rcube[1][3] = rcube[2][3];
            rcube[1][1] = rcube[2][1];
            rcube[2][3] = rcube[5][0];
            rcube[2][1] = rcube[5][2];
            rcube[5][0] = c3;
            rcube[5][2] = c1;
        }
        else if(side == 5){ // 면 5
            c1 = rcube[0][1];
            c0 = rcube[0][1];
            rcube[0][1] = rcube[4][3];
            rcube[0][0] = rcube[4][1];
            rcube[4][3] = rcube[2][2];
            rcube[4][1] = rcube[2][3];
            rcube[2][2] = rcube[3][0];
            rcube[2][3] = rcube[3][2];
            rcube[3][0] = c1;
            rcube[3][2] = c0;
        }
    }
    // 각 면의 4칸이 모두 같은 색상으로 맞춰졌는지 확인
    for(int i=0; i<6; ++i){
        int cur_color = rcube[i][0];
        for(int j=0; j<4; ++j){
            if(rcube[i][j] != cur_color) return false;
        }
    }
    return true;
}
int main(){
    for(int i=0; i<6; ++i){
        for(int j=0; j<4; ++j){ // 각 면마다 4개의 색상 입력
            int color;
            cin >> color;
            cube[i].push_back(color);
        }
    }
    for(int i=0; i<6; ++i){
        for(int c=0; c<2; ++c){ // ccw, cw
            if(rotate(i, c)){ // 한 번 돌려서 큐브 풀 수 있는 경우
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}