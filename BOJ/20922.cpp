// 20922번_겹치는 건 싫어
#include <iostream>
#include <algorithm>
using namespace std;
int n, k, low, high, ans, a[200001], cnt[100001];
int main(){
    cin >> n >> k;
    for(int i=0; i<n; ++i) cin >> a[i];
    // 연속 부분 수열을 슬라이딩 윈도우로 확인
    while(high < n){
        if(cnt[a[high]] == k){
            // 중복 원소 k개이면 윈도우 low부터 줄임
            cnt[a[low]]--;
            low++;
        }
        else{
            cnt[a[high]]++;
            high++;
        }
        ans = max(ans, high-low); // 윈도우 끝-시작점 = 부분 수열 길이
    }
    cout << ans;
    return 0;
}