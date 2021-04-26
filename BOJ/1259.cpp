// 1259번_팰린드롬수
// 어떤 수를 뒤에서부터 읽어도 똑같다면 그 수는 팰린드롬수이다
#include <iostream>
using namespace std;
int Reverse(int n){
    int rst = 0;
    while(n != 0){
        rst *= 10;
        rst += n % 10;
        n /= 10;
    }
    return rst;
}
int main(){
    int num;
    while(cin >> num){
        if(num == 0) break;
        if(Reverse(num) == num) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}