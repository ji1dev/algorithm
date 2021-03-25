// 2775번_부녀회장이 될 테야
#include <iostream>
using namespace std;
int main(){
    int dp[15][15]={0, }, t, k, n;
    cin >> t;
    for(int b=1; b<=14; ++b) 
        dp[0][b] = b;

    for(int a=1; a<=14; ++a){
        dp[a][0] = 0;
        dp[a][1] = 1;
    }
    for(int a=1; a<=14; ++a){
        for(int b=1; b<=14; ++b){
            // a층 b호 = a-1층 1호 + ... + a-1층 b호
            //        = a층 b-1호 + a-1층 b호
            dp[a][b] = dp[a-1][b] + dp[a][b-1];
        }
    }
    while(t--){
        cin >> k >> n;   
        cout << dp[k][n] << "\n";
    }
    return 0;
}