// 15665번_N과 M (11)
// N개 자연수 중 M개를 고른 수열, 같은 수를 여러 번 골라도 됨
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[8], seq[8];
void mkSeq(int len){
    if(len == m){
        for(int i=0; i<m; ++i) cout << seq[i] << " ";
        cout << "\n";
        return;
    }
    int prev = 0;
    for(int i=0; i<n; ++i){
        if(arr[i] != prev){ // 같은 depth에서 같은 숫자를 고르지 않도록 함
            seq[len] = arr[i];
            prev = arr[i];
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