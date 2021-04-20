// 11727번_2xn 타일링 2
#include <iostream>
#define M 10007
using namespace std;
int main(){
    int n, dp[1001] = {0, };
    cin >> n;
    // 초기값
    dp[1] = 1;
    dp[2] = 3;
    for(int i=3; i<=n; ++i){
        // 이전 타일 패턴들 뒤에 2x1 붙이는 경우
        // + 전 전 타일 패턴들 뒤에 중복 안되도록 2x1, 1x2, 2x2 붙이는 경우
        dp[i] = (dp[i-1] + dp[i-2]*2)%M;
    }
    cout << dp[n];
    return 0;
}