// 2580번_스도쿠
#include <iostream>
#include <vector>
#include <stdlib.h>
#define MP make_pair
using namespace std;
int board[9][9];
vector<pair<int, int> > pos;
bool valid(int cnt){
    int bi = pos[cnt].first; // 빈 칸의 좌표
    int bj = pos[cnt].second;
    for(int k=0; k<9; ++k){
        // k가 빈 칸의 좌표와 같지 않은 경우는 넘어감
        if((bj!=k) && (board[bi][k]==board[bi][bj])) return false; // 가로줄 중복 숫자 확인
        if((bi!=k) && (board[k][bj]==board[bi][bj])) return false; // 세로줄 중복 숫자 확인
    }
    int ai = bi/3*3;
    int aj = bj/3*3;
    // 3x3 정사각형 중복 숫자 확인
    for(int i=ai; i<ai+3; ++i){
        for(int j=aj; j<aj+3; ++j){
            if(bi==i && bj==j) continue;
            if(board[bi][bj] == board[i][j]) return false;
        }
    }
    return true;
}
void solve(int cnt){
    // 모든 빈 칸을 조건에 맞도록 채우면 출력하고 종료
    if(cnt == pos.size()){
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    // 빈 칸에 값 채워넣고 조건을 만족하면 다음 빈 칸으로 넘어감
    for(int k=1; k<=9; ++k){
        board[pos[cnt].first][pos[cnt].second] = k;
        if(valid(cnt)) solve(cnt+1);
    }
    board[pos[cnt].first][pos[cnt].second] = 0; // 다시 빈 칸으로
}
int main(){
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            cin >> board[i][j];
            if(board[i][j] == 0){
                pos.push_back(MP(i, j));
            }
        }
    }
    solve(0);
    return 0;
}