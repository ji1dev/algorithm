// 1292번_쉽게 푸는 문제
#include <iostream>
using namespace std;
int a, b, cnt, sum, n;
int main(){
    cin >> a >> b;
    n = 1; // 수열의 첫 숫자는 1
    // b번째 숫자까지 확인하면서 a번째 숫자부터 n을 더함
    // 숫자 n은 n회 등장한다는 조건을 활용
    for(int i=1; i<=b; ++i){ 
        if(cnt >= n){
            cnt = 0;
            n++; // 다음 숫자 확인
        }
        if(i >= a) sum += n;
        cnt++; // 현재 확인중인 숫자의 등장횟수++
    }
    cout << sum;
    return 0;
}