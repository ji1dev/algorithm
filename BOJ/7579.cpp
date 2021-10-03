// 7579번_앱
#include <iostream>
#include <algorithm>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, m, sum;
int mem[101], cost[101], dp[10001];
int main(){
    F_IO;
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> mem[i];
    for(int i=0; i<n; ++i){
        cin >> cost[i]; // 앱 재실행 비용
        sum += cost[i]; // 비용 총합
    }
    for(int i=0; i<n; ++i){
        for(int j=sum; j>=cost[i]; --j){
            // dp[j] = j원으로 확보할 수 있는 메모리
            //       = max(i번째 앱이 활성화 된 경우, i번째 앱이 비활성화 된 경우) 메모리
            // i번째 앱이 활성화 된 경우 = j원에서 i번째 앱 비용 제외했을 때의 메모리 + i번째 앱 메모리
            dp[j] = max(dp[j], dp[j-cost[i]]+mem[i]);
        }
    }
    for(int i=0; i<=sum; ++i){
        if(dp[i] >= m){ // 확보해야되는 메모리 m을 처음으로 만족시키는 비용
            cout << i;
            break;
        }
    }
    return 0;
}