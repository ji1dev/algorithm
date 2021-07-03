// 9663번_N-Queen
#include <iostream>
#include <cmath>
using namespace std;
int n, ans, col[15]; // 퀸이 위치한 열을 기록
bool isPromising(int cur){
    // 현재 열 직전까지 확인하며, 새롭게 놓은 퀸이 기존 퀸들을 공격할 수 없는지 확인
    for(int i=0; i<cur; ++i){
        // 1. i번째, cur번째 행에 있는 퀸이 같은 열에 위치
        // 2. i번째, cur번째 행에 있는 퀸이 같은 대각선에 위치
        if(col[i]==col[cur] || abs(col[i]-col[cur])==abs(i-cur)) return false;
    }
    return true; // 위 조건에 걸리지 않으면 그대로 진행
}
void nQueen(int row){
    if(row == n) ans++; // 퀸 n개를 모두 놓은 경우
    else{
        for(int j=0; j<n; ++j){
            // row번째 행의 j번째 열에 퀸을 배치하고 유망하면 다음 행으로 넘어감
            col[row] = j; 
            if(isPromising(row)) nQueen(row+1);
        }
    }
}
int main(){
    cin >> n;
    nQueen(0);
    cout << ans;
    return 0;
}