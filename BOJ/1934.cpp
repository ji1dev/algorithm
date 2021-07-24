// 1934번_최소공배수
#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        // A = GCD*a, B = GCD*b, LCM = GCD*a*b, 따라서 LCM = A*B/GCD
        cout << a*b/gcd(a,b) << "\n";
    }
    return 0;
}