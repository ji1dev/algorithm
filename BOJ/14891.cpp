// 14891번_톱니바퀴
#include <iostream>
#include <memory.h>
#include <cmath>
#include <deque>
using namespace std;
bool visited[4];
int rotation[4], base[4];
deque<bool> gear[4];
void Check(int i, int d){
    visited[i] = true; // 같은 기어가 여러번 돌아가지 않도록 방문 여부 저장
    rotation[i] = d; // i번째 기어의 회전 방향 저장 (-1:반시계, 0:유지, 1:시계)
    // i번째 기어의 왼쪽 기어 회전 관련
    if(i-1>=0 && !visited[i-1]){
        // 왼쪽 기어와 맞닿은 톱니의 극성이 다른 경우
        if(gear[i-1][2] != gear[i][6]) Check(i-1, -d);
    }
    // i번째 기어의 오른쪽 기어 회전 관련
    if(i+1<=3 && !visited[i+1]){
        // 오른쪽 기어와 맞닿은 톱니의 극성이 다른 경우
        if(gear[i][2] != gear[i+1][6]) Check(i+1, -d);
    }
}
void Rotate(){
    bool tmp;
    for(int i=0; i<4; ++i){
        // 시계 방향 회전
        if(rotation[i] == 1){
            tmp = gear[i].back();
            gear[i].pop_back();
            gear[i].push_front(tmp);
        }
        // 반시계 방향 회전
        else if(rotation[i] == -1){
            tmp = gear[i].front();
            gear[i].pop_front();
            gear[i].push_back(tmp);
        }
    }
}
int calcScore(){
    int sum = 0;
    for(int i=0; i<4; ++i){
        if(gear[i][0] == 1) sum += pow(2, i); // 0:N극, 1:S극
    }
    return sum;
}
int main(){
    char n;
    int k, idx, direction;
    for(int i=0; i<4; ++i){
        for(int j=0; j<8; ++j){
            cin >> n; // 각 기어의 톱니의 극성 저장
            gear[i].push_back(n-'0');
        }
    }
    cin >> k;
    while(k--){
        cin >> idx >> direction; // 회전시킬 기어와 방향
        memset(visited, false, sizeof(visited));
        memset(rotation, 0, sizeof(rotation)); // 기어의 기본 회전 방향은 0 (회전 X)
        Check(idx-1, direction); // 현재 기어와 물려있는 기어들의 회전 방향을 계산
        Rotate(); // 계산된 방향을 바탕으로 기어 회전
    }
    cout << calcScore(); // 4개 기어의 점수를 합산
    return 0;
}