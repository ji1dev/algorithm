// 13458번_시험 감독
#include <iostream>
using namespace std;
int n, b, c, a[1000001];
long long ans;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    cin >> b >> c;
    for(int i=0; i<n; ++i){
        a[i] -= b; // 총감독관 무조건 한명 들어감
        ans++;
        if(a[i] > 0){ // 감시 안받는 응시자 남은 경우 부감독관 맞춰서 들어감
            ans += a[i]/c;
            if(a[i]%c) ans++;
        }
    }
    cout << ans;
    return 0;
}