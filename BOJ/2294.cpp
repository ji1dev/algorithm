// 2294번_동전 2
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, k, coin[101], dp[10001];
int main(){
    cin >> n >> k;
    for(int i=0; i<n; ++i) cin >> coin[i];
    for(int i=1; i<=k; ++i){
        // dp[i] = i원 만드는데 들어간 동전의 최소 개수
        dp[i] = INF;
        for(int j=0; j<n; ++j){
            if(i-coin[j] >= 0){
                // i원 만들기 위해 j원 동전을 사용할 수 있는 경우
                // (i-j)원 만드는 동전 개수에 j원 동전을 하나 추가할 수 있음
                dp[i] = min(dp[i], dp[i-coin[j]]+1);
            }
        }
    }
    if(dp[k] != INF) cout << dp[k];
    else cout << -1;
    return 0;
}