// 16938번_캠프 준비
#include <iostream>
#include <algorithm>
using namespace std;
int n, l, r, x, ans, prob[16];
bool visited[16];
void solve(int cnt, int idx, int sum, int mn, int mx){
    if(cnt >= 2){
        // 두 문제 이상 선택되면 난이도 합과 최대, 최소 난이도 차이가 주어진 값을 만족하는지 확인
        if((l<=sum && sum<=r) && (mx-mn >= x)) ans++;
    }
    for(int i=idx; i<n; ++i){
        if(visited[i] || sum+prob[i] > r) continue; // 합계 r 넘어가면 건너뜀
        visited[i] = true;
        // 현재 선택된 문제들 중 최대, 최소 난이도 계속 갱신
        solve(cnt+1, i+1, sum+prob[i], min(mn, prob[i]), max(mx, prob[i]));
        visited[i] = false;
    }
}
int main(){
    cin >> n >> l >> r >> x;
    for(int i=0; i<n; ++i) cin >> prob[i];
    solve(0, 0, 0, 1000001, 0);
    cout << ans;
    return 0;
}