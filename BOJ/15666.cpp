// 15666번_N과 M (12)
// N개 자연수 중 M개를 고른 수열, 같은 수 여러번 골라도 됨
// 고른 수열은 오름차순, 중복되는 수열을 여러번 출력하면 안됨
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[9], seq[9];
void mkSeq(int len){
    if(len == m){
        for(int i=0; i<m; ++i) cout << seq[i] << " ";
        cout << "\n";
        return;
    }
    int prev = 0;
    for(int i=0; i<n; ++i){
        // 수열의 원소가 오름차순을 유지하도록 함
        // 중복되는 수열을 피하기 위해 같은 depth에서 같은 수를 선택하지 않도록 함
        if(seq[len-1]<=arr[i] && prev!=arr[i]){
            prev = arr[i];
            seq[len] = arr[i];
            mkSeq(len+1);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    mkSeq(0);
    return 0;
}