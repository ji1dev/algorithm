// 2003번_수들의 합 2
#include <iostream>
using namespace std;
int n, m, low, high, sum, cnt, num[10001];
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> num[i];
    // 합계가 m보다 작으면 윈도우를 키우고, m과 같거나 작으면 줄임
    // 윈도우 내부 숫자 합계가 m을 만족하는 경우를 셈
    while(high <= n){
        if(sum >= m){
            sum -= num[low];
            low++;
        }
        else{
            sum += num[high];
            high++;
        }
        if(sum == m) cnt++;
    }
    cout << cnt;
    return 0;
}