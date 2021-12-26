// 1941번_소문난 칠공주
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#define MP make_pair
using namespace std;
int ans;
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
char map[5][5];
bool sel[25]; // 0~25번 학생 선택 여부
bool cond1(){ // 이다솜파 4명 이상인지 확인
    int cnt = 0;
    for(int i=0; i<25; ++i){
        if(sel[i] && map[i/5][i%5]=='S') cnt++;
    }
    if(cnt >= 4) return true;
    return false;
}
bool cond2(){ // 7명이 인접해있는지 확인
    int cnt = 1;
    queue<pair<int, int> > q;
    bool visited[5][5] = {false, };
    for(int i=0; i<25; ++i){
        if(sel[i]){
            q.push(MP(i/5, i%5)); // 시작 학생의 번호로 좌표 계산
            visited[i/5][i%5] = true;
            break;
        }
    }
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k], nj = j+dj[k];
            if(ni<0 || ni>4 || nj<0 || nj>4 || visited[ni][nj]) continue;
            visited[ni][nj] = true;
            if(sel[ni*5+nj]){ // 선택된 학생인 경우
                cnt++;
                q.push(MP(ni, nj));
            }
        }
    }
    if(cnt == 7) return true; // 7명 인접하면 true
    return false;
}
void dfs(int idx, int cnt){
    if(cnt == 7){
        if(cond1() && cond2()) ans++;
        return;
    }
    for(int i=idx; i<25; ++i){
        if(sel[i]) continue;
        sel[i] = true; // i번째 학생 선택
        dfs(i+1, cnt+1);
        sel[i] = false;
    }
}
int main(){
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            cin >> map[i][j];
        }
    }
    dfs(0, 0); // 학생 idx, 선택 cnt
    cout << ans;
    return 0;
}