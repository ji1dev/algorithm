// 24389번_2의 보수
#include <iostream>
using namespace std;
int n, m, cnt;
int main(){
    cin >> n;
    m = ~n+1; // 2의 보수
    m = n^m; // 원본과 2의 보수의 서로 다른 비트만 체크
    for(int i=0; i<32; ++i){
        if(m & (1<<i)) cnt++; // 다른 비트의 개수 count
    }
    cout << cnt;
    return 0;
}