// 15662번_톱니바퀴 (2)
#include <iostream>
#include <deque>
#include <memory.h>
using namespace std;
int t, k, n, d, ans, dir[1000];
deque<bool> gear[1000];
bool visited[1000];
void setDir(int n, int d){
    visited[n] = true; // 중복 회전 방지
    dir[n] = d; // n번 기어를 d방향으로 회전
    for(int i=0; i<t; ++i){
        // 인접 기어와 맞닿은 극이 다르면 인접 기어를 반대방향으로 회전시킴
        if(!visited[n-1] && n-1>=0){        
            if(gear[n-1][2] != gear[n][6]) setDir(n-1, -d);
        }
        if(!visited[n+1] && n+1<t){
            if(gear[n+1][6] != gear[n][2]) setDir(n+1, -d);
        }
    }
}
void rotate(){
    for(int i=0; i<t; ++i){
        bool tmp;
        if(dir[i] == -1){ // ccw
            tmp = gear[i].front();
            gear[i].pop_front();
            gear[i].push_back(tmp);
        }
        else if(dir[i] == 1){ // cw
            tmp = gear[i].back();
            gear[i].pop_back();
            gear[i].push_front(tmp);
        }
    }
}
int main(){
    cin >> t;
    for(int i=0; i<t; ++i){
        for(int j=0; j<8; ++j){
            int polar; // 각 기어의 극성 정보 (12시 방향부터 cw)
            scanf("%1d", &polar); // N: 0, S: 1
            gear[i].push_back(polar);
        }
    }
    cin >> k;
    for(int i=0; i<k; ++i){
        memset(visited, false, sizeof(visited));
        memset(dir, 0, sizeof(dir)); // 기본 상태는 회전 x
        cin >> n >> d;
        setDir(n-1, d); // n번째 기어 d방향으로 회전 (ccw: -1, cw: 1, keep: 0)
        rotate(); // 실제 회전 반영
    }
    for(int i=0; i<t; ++i){
        if(gear[i][0] == 1) ans++;
    }
    cout << ans;
    return 0;
}