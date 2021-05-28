// 11047번_동전 0
#include <iostream>
using namespace std;
int main(){
    // n가지 종류의 동전을 최소로 사용하여 k원을 만드는 방법
    int n, k, cnt = 0, value[11] = {0, };
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> value[i];
    
    // 큰 액수의 동전부터 확인함
    for(int i=n; i>=1; --i){
        cnt += k/value[i]; // k원을 현재 동전을 최대로 사용하여 채우기
        k %= value[i]; // 나머지 값
    }
    cout << cnt;
    return 0;
}