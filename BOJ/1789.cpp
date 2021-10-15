// 1789번_수들의 합
#include <iostream>
using namespace std;
long long s, sum;
int ans, i = 1;
int main(){
    cin >> s;
    while(1){
        sum += i;
        // 숫자 합 s넘어가면 지금까지 더한 숫자 개수 출력
        if(sum > s){
            cout << ans;
            break;
        }
        ans++;
        i++;
    }
    return 0;
}