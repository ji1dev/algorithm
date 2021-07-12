// 9465번_스티커
#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
int main(){
    int n, t;
    cin >> t;
    while(t--){
        int arr[2][MAX] = {0, }, dp[2][MAX] = {0, };
        cin >> n;
        for(int i=0; i<2; ++i){
            for(int j=0; j<n; ++j){
                cin >> arr[i][j];
            }
        }
        for(int j=0; j<n; ++j){
            // 한 열을 건너뛰고 다음 열의 스티커를 떼면 이득이 더 클 수도 있음
            // 예를 들어 0행 j열까지 스티커를 떼었을 때 최대 점수는 0행 j열의 스티커의 점수에
            // 대각선 아래(1행 j-1열) or 한 열 건너뛴 대각선 아래(1행 j-2열)까지의 점수 합 중 더 큰 값을 더한 값
            dp[0][j] = arr[0][j]+max(dp[1][j-1], dp[1][j-2]);
            dp[1][j] = arr[1][j]+max(dp[0][j-1], dp[0][j-2]);
        }
        cout << max(dp[0][n-1], dp[1][n-1]) << "\n";
    }
    return 0;
}