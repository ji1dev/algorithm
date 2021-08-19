// 15652번_N과 M (4)
// 1~N까지 자연수 중 M개를 고른 수열, 같은 수 여러번 선택 가능, 수열 원소 오름차순
#include <iostream>
using namespace std;
int n, m, seq[9];
void mkSeq(int len){
    if(len == m){
        for(int i=0; i<m; ++i) cout << seq[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; ++i){
        if(seq[len-1] <= i){ // 수열 원소의 오름차순 유지
            seq[len] = i;
            mkSeq(len+1);
        }
    }
}
int main(){
    cin >> n >> m;
    mkSeq(0);
    return 0;
}