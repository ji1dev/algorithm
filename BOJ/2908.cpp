// 2908번_상수
#include <iostream>
using namespace std;
int Reverse(int num){
    int rst = 0;
    while(num != 0){
        rst *= 10;
        rst += num % 10;
        num /= 10;
    }
    return rst;
}
int main(){
    int a, b;
    cin >> a >> b;
    a = Reverse(a);
    b = Reverse(b);
    if(a > b) cout << a;
    else cout << b;
    return 0;
}