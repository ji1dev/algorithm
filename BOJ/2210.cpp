// 2210번_숫자판 점프
#include <iostream>
#include <set>
using namespace std;
int map[5][5];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
set<int> s; // 중복 포함시키지 않기 위해 set사용
void dfs(int i, int j, int len, int num){
    if(len == 6){
        s.insert(num);
        return;
    }
    for(int k=0; k<4; ++k){
        int ni = i+di[k];
        int nj = j+dj[k];
        if(ni<0 || ni>=5 || nj<0 || nj>=5) continue;
        dfs(ni, nj, len+1, num*10+map[ni][nj]);
    }
}
int main(){
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            dfs(i, j, 1, map[i][j]); // 좌표, 길이, 첫 자리 숫자
        }
    }
    cout << s.size(); // 만들 수 있는 여섯 자리 수들 중 중복 제외한 수들의 개수
    return 0;
}