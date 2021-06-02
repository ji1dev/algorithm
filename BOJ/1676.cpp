// 1676번_팩토리얼 0의 개수
#include <iostream>
using namespace std;
int main(){
    int n, ans = 0;
    cin >> n;
    if(n<2){
        cout << n;
        exit(0);
    }
    // 0의 개수는 10을 몇 번 곱했는지와 같음
    // 이는 n!의 소인수 중 2x5 쌍의 개수와 같고, 항상 5가 더 적으므로 5의 개수를 count함
    for(int i=5; i<=n; i*=5){ // 5^m의 수 까지 확인해야됨 (m=1, 2, ...)
        for(int j=i; j<=n; j+=i){
            ans++;
        }
    }
    cout << ans;
    return 0;
}