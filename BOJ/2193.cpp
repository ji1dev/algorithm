// 2193번_이친수
// N자리 이친수의 개수를 구하는 프로그램을 작성하시오.
#include <iostream>
using namespace std;
int main(){
    int n;
    long d[90];
    cin >> n;
    d[1] = 1; // 1(2)
    d[2] = 1; // 10(2)
    for(int i=3; i<=n; ++i){
        d[i] = d[i-1]+d[i-2];
    }
    cout << d[n];
    return 0;
}