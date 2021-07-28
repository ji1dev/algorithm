// 11060번_점프 점프
#include <iostream>
#include <algorithm>
#include <memory.h>
#define L 987654321
using namespace std;
int n, dp[1001], jmp[1001];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> jmp[i];
        dp[i] = L;
    }
    dp[0] = 0; // dp[i] = i번째 칸에 도달하기 위한 최소 점프 횟수
    for(int i=0; i<n; ++i){
        for(int j=1; j<=jmp[i]; ++j){ // jmp[i] 이하 값 만큼 점프 가능함
            if(i+j >= n) break; // 점프 했는데 칸 벗어나면 이후 그보다 큰 폭으로 점프 할 필요 없음
            dp[i+j] = min(dp[i+j], dp[i]+1); // 점프 한 칸의 기존 값과 현재 칸에서 점프한 경우 중 최솟값으로 갱신
        }
    }
    if(dp[n-1] == L) cout << -1;
    else cout << dp[n-1];
    return 0;
}