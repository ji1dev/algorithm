// 11055번_가장 큰 증가 부분 수열
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, a[1000] = {0, }, dp[1000] = {0, }, ans = 0;
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    // dp[i] = i번째 수 까지 증가 부분 수열의 합
    for(int i=0; i<n; ++i){
        dp[i] = a[i];
        // i번째 수 = 현재 수, j번째 수 = i 이전까지의 수들
        // i번째 수가 j번째 수보다 크고 (증가하는 수열임을 의미),
        // i번째 수 까지 증가 부분 수열의 합보다 
        // j번째 수 까지 증가 부분 수열의 합에 i번째 수를 더한것이 더 크면 갱신
        for(int j=0; j<i; ++j){
            if(a[i]>a[j] && dp[i]<dp[j]+a[i]){
                dp[i] = dp[j]+a[i];
            }
        }
        // 최대합 갱신
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}