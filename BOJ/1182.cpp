// 1182번_부분수열의 합
#include <iostream>
using namespace std;
int n, s, arr[20], cnt = 0;
void MakeSubset(int idx, int sum){
    sum += arr[idx];
    if(idx >= n) return;
    if(sum == s) cnt++;
    // arr[idx]의 수를 수열에 포함시키는 경우와 포함시키지 않는 경우로 나눠 계산
    MakeSubset(idx+1, sum);
    MakeSubset(idx+1, sum-arr[idx]);
}
int main(){
    cin >> n >> s;
    for(int i=0; i<n; ++i) cin >> arr[i];
    MakeSubset(0, 0);
    cout << cnt;
    return 0;
}