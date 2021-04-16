// 13398번_연속합 2
#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
int n, ans;
int arr[MAX+1], dp[MAX+1][2];
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> arr[i];

    // d[i][0] = i번째 수 까지 선택했을 때 연속합의 최댓값 (수 제거 X)
    // d[i][1] = i번째 수 까지 선택했을 때 연속합의 최댓값 (수 하나 제거)
    dp[1][0] = arr[1];
    ans = arr[1];

    for(int i=2; i<=n; ++i){
        // 수 제거 안하는 경우
        // 현재 수 까지 더한 연속합보다 현재 수가 더 크면 새로운 연속합 시작
        // 나머지 경우 기존 연속합을 이어감
        dp[i][0] = max(arr[i], dp[i-1][0]+arr[i]); 

        // 수 하나 제거하는 경우
        // 현재 수 제거하는 경우 이전 수 까지의 최대 연속합을 그대로 가져옴
        // 이전에 수를 제거했으면 현재 수는 반드시 포함해야 됨
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]+arr[i]); 
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans;
    return 0;
}