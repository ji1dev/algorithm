// 16234번_인구 이동
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <memory.h>
#define MP make_pair
using namespace std;
int n, l, r, a_cnt, a_sum, days, map[51][51];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
bool isMove, visited[51][51];
queue< pair<int, int> > q;
vector< pair<int, int> > alliance;
void Move(){
    int avg = a_sum/a_cnt;
    for(int i=0; i<alliance.size(); ++i){
        map[alliance[i].first][alliance[i].second] = avg;
    }
    isMove = true; // 인구 이동이 발생함
}
void tryAlliance(int si, int sj){
    q.push(MP(si, sj));
    visited[si][sj] = true;
    alliance.push_back(MP(si, sj));
    a_cnt++;
    a_sum += map[si][sj];
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=n || visited[ni][nj]) continue;
            int diff = abs(map[ni][nj]-map[i][j]);
            // 조건 충족시 연합에 추가하고 연합 내 인구와 국가 개수 갱신
            if(diff>=l && diff<=r){
                q.push(MP(ni, nj));
                visited[ni][nj] = true;
                alliance.push_back(MP(ni, nj));
                a_cnt++;
                a_sum += map[ni][nj];
            }
        }
    }
    if(alliance.size() >= 2) Move(); // 연합국 두 곳 이상이면 인구이동 발생
    alliance.clear(); // 연합 해체
    a_sum = a_cnt = 0;
}
int main(){
    cin >> n >> l >> r;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> map[i][j];
        }
    }
    while(true){
        memset(visited, false, sizeof(visited));
        isMove = false;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(!visited[i][j]) tryAlliance(i, j);
            }
        }
        if(isMove) days++; // 인구 이동 발생한 날++
        else break; // 더 이상 인구 이동이 없으면 종료
    }
    cout << days;
    return 0;
}