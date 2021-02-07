// 2609번_최대공약수와 최소공배수
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
} 

int main(){
    int a, b, g;
    cin >> a >> b;
    g = gcd(a, b); // 유클리드 호제법으로 GCD를 구함
    cout << g << "\n";
    cout << (a*b)/g << "\n"; // LCM = (A*B)/GCD
    return 0;
}