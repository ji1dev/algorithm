// 2023번_신기한 소수
#include <iostream>
using namespace std;
int n;
bool isPrime(int num){
    for(int i=2; i*i<=num; ++i){
        if(num%i == 0) return false;
    }
    return true;
}
void dfs(int num, int len){
    if(len == n){
        cout << num << "\n";
        return;
    }
    for(int i=1; i<=9; i+=2){ // 짝수는 확인할 필요 없음
        int next = num*10+i;
        if(isPrime(next)) dfs(next, len+1);
    }
}
int main(){
    cin >> n;
    dfs(2, 1); // 첫 자리로 올 수 있는 수는 2, 3, 5, 7
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);
    return 0;
}