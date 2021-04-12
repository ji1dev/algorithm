// 11722번_가장 긴 감소하는 부분 수열
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, a[1001] = {0, }, dp[1001] = {0, }, maxlen = 1;
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    // dp[i] = i번째 수 까지 가장 긴 감소 부분 수열의 길이
    dp[1] = 1;
    for(int i=2; i<=n; ++i){
        // 현재 확인하려는 원소보다 큰 원소들 중 
        // 가장 가까운 값 까지의 가장 긴 감소하는 부분 수열 길이 + 1
        int nearest = 0;
        for(int j=1; j<i; ++j){
            if(a[j] > a[i]){
                nearest = max(nearest, dp[j]);
            }
            dp[i] = nearest+1;
        }
        maxlen = max(maxlen, dp[i]);
    }
    cout << maxlen;
    return 0;
}