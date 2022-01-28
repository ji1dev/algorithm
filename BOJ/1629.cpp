// 1629번_곱셈
#include <iostream>
#define ll long long
using namespace std;
int a, b, c;
ll solve(ll n){
    if(n == 1) return a%c; // 지수 1이면 a그대로
    ll res = solve(n/2); // 지수의 절반인 n/2으로 재귀 돌림
    if(n%2 == 1) // 지수가 홀수이면 a를 한번 더 곱함 (e.g. a^5 = (a^2)^2*a)
        return (res*res%c)*a%c;
    return res*res%c; // 지수가 짝수이면 res그대로
}
int main(){
    cin >> a >> b >> c; // a^b%c
    cout << solve(b);
    return 0;
}