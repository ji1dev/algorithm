// 9251번_LCS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string seq1, seq2;
int len1, len2, ans, dp[1002][1002];
int main(){
    cin >> seq1 >> seq2;
    len1 = seq1.length();
    len2 = seq2.length();
    for(int i=1; i<=len1; ++i){
        for(int j=1; j<=len2; ++j){
            // dp[i][j] = 수열1의 i번째 문자, 수열2의 j번째 문자까지의 LCS길이
            // 두 수열에서 비교하는 문자가 같으면 직전 LCS+1, 다르면 직전 LCS길이 중 더 큰 값을 선택
            if(seq1[i-1] == seq2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[len1][len2];
    return 0;
}