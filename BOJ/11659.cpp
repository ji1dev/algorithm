// 11659번_구간 합 구하기 4
#include <iostream>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    F_I;
    int n, m, i, j, tmp, sum[100001] = {0, };
    cin >> n >> m;
    for(int k=1; k<=n; ++k){
        cin >> tmp;
        sum[k] = sum[k-1]+tmp;
    }
    for(int k=0; k<m; ++k){
        cin >> i >> j;
        // j까지 누적합 - i이전까지 누적합 (필요없는 앞부분 제외)
        cout << sum[j]-sum[i-1] << "\n";
    }
    return 0;
}