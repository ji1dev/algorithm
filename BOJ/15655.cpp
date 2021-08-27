// 15655번_N과 M (6)
// N개의 자연수 중에서 M개를 고른 수열
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[9], seq[9];
bool visited[9];
void mkSeq(int len){
    if(len == m){
        for(int i=0; i<m; ++i) cout << seq[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0; i<n; ++i){
        // 중복 X, 수열의 원소는 오름차순으로
        if(!visited[i] && seq[len-1]<=arr[i]){
            seq[len] = arr[i];
            visited[i] = true;
            mkSeq(len+1);
            visited[i] = false;
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