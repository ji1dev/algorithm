// 17427번_약수의 합 2
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    unsigned long long sum = 0;
    cin >> n;
    /*
    주어진 수와 같거나 작은 모든 자연수의 약수의 합을 구하기 위해
    (각 약수가 등장하는 횟수 * 해당 약수)를 모두 더함
    */
    for(int i=1; i<=n; ++i){
        sum += i * (n/i);
    }
    cout << sum << "\n";
}