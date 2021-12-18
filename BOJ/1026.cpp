// 1026번_보물
#include <iostream>
#include <algorithm>
using namespace std;
int n, ans, a[51], b[51];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    for(int i=0; i<n; ++i){
        ans += a[i]*b[n-i-1];
    }
    cout << ans;
    return 0;
}