// 2156번_포도주 시식
#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;
int main(){
    int n, cnt = 1, a[MAX], dp[MAX] = {0, };
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    dp[1] = a[1];
    dp[2] = dp[1]+a[2];
    if(n<=2){
        cout << dp[n];
        return 0;
    }
    for(int i=3; i<=n; ++i){
        dp[i] = dp[i-3]+a[i-1]+a[i]; // (i-3)번째 잔 까지 선택결과 + 선택X + 선택 + 선택
        dp[i] = max(dp[i], dp[i-2]+a[i]); // (i-2)번째 잔 까지 선택결과 + 선택X + 선택
        dp[i] = max(dp[i], dp[i-1]); // (i-1)번째 잔 까지 선택결과 + 선택X
    }
    cout << dp[n];
    return 0;
}