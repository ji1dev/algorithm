// 1463번_1로 만들기
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, d[1000001];
    cin >> n;
    // 1을 빼는 연산으로 1을 만드는 방법을 기록해 두고 
    // 현재 수가 2나 3으로 나누어 떨어지면 연산 횟수를 갱신함
    d[1] = 0;
    for(int i=2; i<=n; ++i){
        d[i] = d[i-1]+1;
        if(i%2 == 0) d[i] = min(d[i], d[i/2]+1);
        if(i%3 == 0) d[i] = min(d[i], d[i/3]+1);
    }
    cout << d[n];
    return 0;
}