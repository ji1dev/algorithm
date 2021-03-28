// 2231번_분해합
// 자연수 n의 분해합은 n과 n을 이루는 각 자리수의 합을 의미함
// 어떤 자연수 m의 분해합이 n인 경우, m을 n의 생성자라고 함
// 예를 들어 256의 생성자는 245임 (245+2+4+5 = 256)
#include <iostream>
using namespace std;
int find(int n){
    int m = 1, sum, tmp;
    while(1){
        sum = m; // 각 자리수를 더하기 전 m으로 미리 설정
        tmp = m; // 현재 확인할 자연수
        while(tmp){
            // 각 자리수를 sum에 더해서 분해합을 구함
            sum += tmp%10;
            tmp /= 10;
        }
        // 분해합이 n과 같으면 생성자를 찾은 경우
        // 확인한 자연수가 n과 같으면 생성자가 없는 경우
        if((sum == n) || (m == n)) break;
        m++;
    }
    return m;
}
int main(){
    int n, rst;
    cin >> n;
    rst = find(n);
    if(rst == n) cout << 0 << "\n";
    else cout << rst << "\n";
    return 0;
}