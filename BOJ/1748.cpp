// 1748번_수 이어 쓰기 1
#include <iostream>
using namespace std;
int main(){
    int n, cnt = 0, ans = 0;
    cin >> n;
    // 1자리 수 * 9개, 2자리 수 * 90개, ...
    for(int i=9; i<=n; i*=10){
        cnt++;
        n -= i;
        ans += cnt*i;
    }
    ans += n*(++cnt); // 남은 수들의 자리 더해주기
    cout << ans << "\n";
    return 0;
}