// 2230번_수 고르기
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, low, high, ans, num[100001];
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> num[i];
    sort(num, num+n);
    ans = 2e9+1;
    high = 1;
    while(high < n){
        int diff = num[high]-num[low];
        // 차이가 m보다 작으면 윈도우 크기 키워서 확인, 크면 크기 줄여서 확인
        // 차이 m인 경우 찾으면 탈출
        if(diff < m) high++;
        else if(diff > m){
            ans = min(ans, diff);
            low++;
        }
        else{
            ans = m;
            break;
        }
    }
    cout << ans;
    return 0;
}