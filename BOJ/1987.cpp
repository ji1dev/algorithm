// 1987번_알파벳
#include <iostream>
#include <algorithm>
using namespace std;
int r, c, ans, di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
char arr[21][21];
bool used[26];
void dfs(int i, int j, int cnt){
    used[arr[i][j]-'A'] = true;
    ans = max(ans, cnt); // 지날 수 있는 최대 칸 수 갱신
    for(int k=0; k<4; ++k){
        int ni = i+di[k];
        int nj = j+dj[k];
        if(ni<0 || ni>=r || nj<0 || nj>=c) continue;
        if(!used[arr[ni][nj]-'A']){
            dfs(ni, nj, cnt+1);
            used[arr[ni][nj]-'A'] = false;
        }
    }
}
int main(){
    cin >> r >> c;
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            scanf("%1s", &arr[i][j]);
        }
    }
    dfs(0, 0, 1); // 시작 칸 포함
    cout << ans;
    return 0;
}