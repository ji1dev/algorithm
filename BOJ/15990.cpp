// 15990번_1, 2, 3 더하기 5
#include <iostream>
#define M 1000000009
using namespace std;
long long dp[100001][4];
int main(){
    int t, n;

    // dp[i][j] = 1,2,3의 합으로 i번째 수를 만들 때 마지막 항이 j인 경우
    dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
    dp[2][1] = 0; dp[2][2] = 1; dp[2][3] = 0;
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;

    // 같은 수가 연속으로 올 수 없음을 주의할 것
    for(int i=4; i<=100000; ++i){
        dp[i][1] = (dp[i-1][2] + dp[i-1][3])%M;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3])%M;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2])%M;
    }
    cin >> t;
    for(int tc=0; tc<t; ++tc){
        cin >> n;
        cout << (dp[n][1]+dp[n][2]+dp[n][3])%M << "\n";
    }
    return 0;
}