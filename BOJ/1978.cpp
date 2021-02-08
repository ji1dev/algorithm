// 1978번_소수 찾기
#include <iostream>
using namespace std;
int main(){
    int n, p, cnt;
    cin >> n;
    cnt = n;
    while(n--){
        cin >> p;
        if(p == 1){
            cnt--;
            continue;
        }
        // 합성수 p = a * b 일때 a, b 중 적어도 하나는 p의 제곱근보다 작거나 같음
        // p를 p의 제곱근보다 큰 수로 나누면 이미 약수라고 판단한 수를 몫으로 가지거나 나머지가 발생
        // 따라서 p의 제곱근 까지만 검사하면 됨
        for(int i=2; i*i<=p; ++i){
            if(p%i == 0){
                cnt--;
                break;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}