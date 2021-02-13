// 1476번_날짜 계산
#include <iostream>
using namespace std;
int main(){
    int E, S, M, year = 1;
    cin >> E >> S >> M;
    
    // E, S, M 은 범위를 넘어가면 1이 됨
    // 범위를 넘어간 만큼 빼주고 각 범위로 나누어 떨어지는지 확인함
    while(1){
        if(((year-E)%15 == 0) && ((year-S)%28 == 0) && ((year-M)%19 == 0)) break;
        year++;
    }
    cout << year << "\n";
    return 0;
}