// 17089번_세 친구
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, mn_cnt, cnt[4001];
bool isValid, e[4001][4001];
void solve(){
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            if(!e[i][j]) continue; // 친구 관계 있는 경우만 확인
            for(int k=j+1; k<=n; ++k){
                if(!e[j][k] || !e[k][i]) continue;
                isValid = true; // 3명의 친구 관계 형성 가능함을 표시
                mn_cnt = min(mn_cnt, (cnt[i]+cnt[j]+cnt[k]-6));
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = true; // 친구 관계
        cnt[a]++; // 친구 수
        cnt[b]++;
    }
    mn_cnt = 987654321;
    solve();
    cout << (isValid ? mn_cnt : -1);
    return 0;
}