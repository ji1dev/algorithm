// 15656번_N과 M (7)
// N개 자연수 중 M개를 고른 수열, 같은 수 여러번 골라도 됨
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
    for(int i=0; i<n; ++i){
        seq[len] = arr[i];
        mkSeq(len+1);
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    mkSeq(0);
    return 0;
}