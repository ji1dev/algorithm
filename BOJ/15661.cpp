// 15661번_링크와 스타트
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int n, mn_diff, s[21][21];
bool visited[21]; // t1에 포함여부
void solve(int idx){
    if(idx >= n){
        int t1 = 0, t2 = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(visited[i] && visited[j]) t1 += s[i][j];
                else if(!visited[i] && !visited[j]) t2 += s[i][j];
            }
        }
        mn_diff = min(mn_diff, abs(t1-t2)); // 능력치 차이의 최솟값 갱신
        return;
    }
    for(int i=idx; i<n; ++i){
        if(visited[i]) continue;
        visited[i] = true; // i번 선수를 t1에 포함
        solve(i+1);
        visited[i] = false;
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> s[i][j];
        }
    }
    mn_diff = 987654321;
    solve(0);
    cout << mn_diff;
    return 0;
}