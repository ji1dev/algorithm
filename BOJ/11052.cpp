// 11052번_카드 구매하기
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, p[1001], d[1001]={0, };
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> p[i];
    d[1] = p[1];
    for(int i=2; i<=n; ++i){
        for(int j=1; j<=i; ++j){
            d[i] = max(d[i-j]+p[j], d[i]);
        }
    }
    cout << d[n];
    return 0;
}