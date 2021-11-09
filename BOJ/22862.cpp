// 22862번_가장 긴 짝수 연속한 부분 수열 (large)
#include <iostream>
#include <algorithm>
using namespace std;
int n, k, low, high, odd, max_len, a[1000001];
int main(){
    cin >> n >> k;
    for(int i=0; i<n; ++i) cin >> a[i];
    while(high < n){
        if(a[high]%2 == 1) odd++;
        // 홀수 개수가 k개 넘어가면 low 위치에 홀수가 있으면 개수 줄이고 low 키움
        while(odd > k){
            if(a[low]%2 == 1) odd--;
            low++;
        }
        // 홀수 개수 k범위에 들어오면 부분 수열에서 홀수 개수를 제외한 값으로 
        // 가장 긴 짝수 부분 수열 길이를 갱신
        if(odd <= k) max_len = max(max_len, high-low+1-odd);
        high++;
    }
    cout << max_len;
    return 0;
}