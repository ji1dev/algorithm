// 15486번_퇴사 2
#include <iostream>
#include <algorithm>
#define MAX 1500000
using namespace std;
int n, t[MAX+1], p[MAX+1], dp[MAX+1], maxProfit;
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> t[i] >> p[i];
    }
    for(int i=1; i<=n+1; ++i){
        maxProfit = max(maxProfit, dp[i]); // 최대 보유 금액 갱신
        if(i+t[i] <= n+1){ // 퇴사 이전인 경우
            // dp[i+t[i]] = i일부터 t[i]일 일한 뒤 보유 금액
            //            = max(i+t[i]일의 보유 금액, 최대 보유 금액에 i일의 금액을 더한 값)
            dp[i+t[i]] = max(dp[i+t[i]], maxProfit+p[i]);
        }
    }
    cout << maxProfit;
    return 0;
}