// 9095번_1, 2, 3 더하기
#include <iostream>
using namespace std;
int main(){
    int num[11] = {1, 2, 4, 0}; // 1, 2, 3의 합은 미리 계산
    int t, n;
    cin >> t;
    // n(4<=n<=10)을 1, 2, 3의 합으로 나타내는 방법의 수 계산
    for(int i=3; i<10; ++i){
        num[i] = num[i-1] + num[i-2] + num[i-3];
    }
    while(t--){  
        cin >> n;
        cout << num[n-1] << "\n";
    }
    return 0;
}