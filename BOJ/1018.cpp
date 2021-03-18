// 1018번_체스판 다시 칠하기
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m, ans = 999999;
string board[50];
string WBpattern[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BWpattern[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
int check(int y, int x, char first){
    int cnt = 0;
    if(first == 'w'){
        for(int i=y; i<y+8; ++i){
            for(int j=x; j<x+8; ++j){
                // 패턴의 row, column index를 0부터 돌리기 위해 i-y, j-x 함
                if(board[i][j] != WBpattern[i-y][j-x]) cnt++;
            }
        }
    }
    else if(first == 'b'){
        for(int i=y; i<y+8; ++i){
            for(int j=x; j<x+8; ++j){
                if(board[i][j] != BWpattern[i-y][j-x]) cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> board[i];
    for(int i=0; i<=n-8; ++i){
        for(int j=0; j<=m-8; ++j){
            // white로 시작하는 패턴과 black으로 시작하는 패턴 모두 검사
            // 전부 갈아 엎는쪽이 더 적게 색칠하고 체스판을 만들 수 있기 때문
            ans = min(ans, min(check(i,j,'w'), check(i,j,'b')));
        }
    }
    cout << ans;
    return 0;
}