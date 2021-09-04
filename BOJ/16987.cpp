// 16987번_계란으로 계란치기
#include <iostream>
#include <algorithm>
#define MP make_pair
using namespace std;
int n, ans;
pair<int, int> egg[9];
void dfs(int idx){
    if(idx == n){ // 깬 계란 개수의 최댓값 갱신
        int cnt = 0;
        for(int i=0; i<n; ++i){
            if(egg[i].first <= 0) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    int bs = egg[idx].first; // 들고있는 계란
    int bw = egg[idx].second;
    if(bs <= 0) dfs(idx+1); // 들고있는 계란이 깨진 계란이면 다음 계란으로 넘어감
    else{
        bool isLast = true;
        for(int i=0; i<n; ++i){
            int ns = egg[i].first; // 놓여있는 계란
            int nw = egg[i].second;
            if(i==idx || ns<=0) continue; // 들고있는 계란이나 깨진 계란은 넘어감
            egg[idx].first -= nw;
            egg[i].first -= bw;
            isLast = false;
            dfs(idx+1);
            egg[idx].first += nw;
            egg[i].first += bw;
        }
        if(isLast) dfs(n); // 다음 계란이 없으면 깬 계란 개수 갱신
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        int s, w;
        cin >> s >> w;
        egg[i] = MP(s, w);
    }
    dfs(0); // 계란 idx, 깬 계란 개수
    cout << ans;
    return 0;
}