// 3184번_양
#include <iostream>
using namespace std;
int r, c, o_sum, v_sum, o_cnt, v_cnt;
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
char map[251][251];
bool visited[251][251];
void dfs(int i, int j){
    visited[i][j] = true;
    if(map[i][j] == 'o') o_cnt++; // 양 발견
    else if(map[i][j] == 'v') v_cnt++; // 늑대 발견
    for(int k=0; k<4; ++k){
        int ni = i+di[k];
        int nj = j+dj[k];
        if(ni<0 || ni>=r || nj<0 || nj>=c) continue;
        if(!visited[ni][nj] && map[ni][nj]!='#') dfs(ni, nj);
    }
}
int main(){
    cin >> r >> c;
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            scanf("%1s", &map[i][j]);
        }
    }
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            // 방문X, 현재 칸이 울타리가 아니면 dfs시작
            // 탈출시 한 울타리에 포함된 양과 늑대의 수가 계산됨
            if(!visited[i][j] && map[i][j]!='#'){
                o_cnt = v_cnt = 0;
                dfs(i, j);
                if(o_cnt > v_cnt) o_sum += o_cnt; // 양이 더 많은 경우
                else v_sum += v_cnt; // 늑대가 더 많거나 같은 경우
            }
        }
    }
    cout << o_sum << " " << v_sum;
    return 0;
}