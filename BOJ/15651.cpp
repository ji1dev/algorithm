// 15651번_N과 M (3)
// 1~N까지 자연수 중 M개를 고른 수열, 같은 수 여러번 선택 가능
#include <iostream>
using namespace std;
int n, m, seq[8];
void mkSeq(int len){
    if(len == m){
        for(int i=0; i<m; ++i) cout << seq[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; ++i){
        seq[len] = i;
        mkSeq(len+1);
    }
}
int main(){
    cin >> n >> m;
    mkSeq(0);
    return 0;
}