// 15657번_N과 M (8)
// N개 자연수 중 M개를 고른 수열, 같은 수 여러번 골라도 됨
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, seq[9], arr[9];
void mkSeq(int len){
    if(len == m){
        for(int i=0; i<m; ++i) cout << seq[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0; i<n; ++i){
        if(seq[len-1] <= arr[i]){
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