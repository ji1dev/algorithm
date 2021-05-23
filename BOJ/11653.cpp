// 11653번_소인수분해
#include <iostream>
#include <cmath> 
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=2; i<=sqrt(n); ++i){
        while(n%i == 0){
            // 현재 수로 나누어 떨어지는 동안 계속 출력
            cout << i << "\n";
            n/=i;
        }
    }
    // n이 1인경우 이미 소인수를 전부 찍은 경우이므로 추가 출력 필요 없음
    if(n!=1) cout << n;
    return 0;
}