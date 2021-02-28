// 11050번_이항 계수 1
#include <iostream>
using namespace std;
// n개 원소 중 r개 원소를 선택하는 경우의 수 (조합)
int Combination(int n, int r){
    // n=r 이거나 r=0 이면 원소를 선택하는 경우는 한가지로 고정
    // 위 조건을 만족하기 전까지는 n을 선택하고 나머지 n-1개 중 r-1개를 선택하는 경우와
    // n을 선택하지 않고 나머지 n-1개 중 r개를 선택하는 경우의 합을 각각 재귀로 구함
    if((n == r) || (r == 0)) return 1;
    return Combination(n-1, r-1) + Combination(n-1, r);
}
int main(){
    int n, r;
    cin >> n >> r;
    cout << Combination(n, r);
    return 0;
}