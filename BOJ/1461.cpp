// 1461번_도서관
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, idx, ans, loc[10001];
int main(){
    cin >> n >> m; // 한번에 m권씩 옮길 수 있음
    for(int i=0; i<n; ++i){
        cin >> loc[i];
        if(loc[i] < 0) idx++; // 음수 구간 끝나는 인덱스로 사용
    }
    sort(loc, loc+n);
    for(int i=0; i<idx; i+=m) ans += abs(loc[i]*2); // 음수 구간 왕복
    for(int i=n-1; i>=idx; i-=m) ans += loc[i]*2; // 양수 구간 왕복
    ans -= max(abs(loc[0]), abs(loc[n-1])); // 가장 멀리 있는 책은 왕복 안해도 됨
    cout << ans;
}