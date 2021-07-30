// 1986번_체스
#include <iostream>
using namespace std;
int n, m, a, r, c, cnt, board[1001][1001];
int qdi[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int qdj[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int kdi[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int kdj[] = {-2, -1, 1, 2, 2, 1, -1, -2};
void mvQueen(int i, int j){
    for(int k=0; k<8; ++k){
        int ni = i+qdi[k];
        int nj = j+qdj[k];
        // 범위 벗어나지 않고, 장애물을 만나기 전까지 이동
        while(ni>=1 && ni<=n && nj>=1 && nj<=m && board[ni][nj]<=0){
            board[ni][nj] = -1;
            ni += qdi[k]; // 같은 방향으로 계속 이동
            nj += qdj[k];
        }
    }       
}
void mvKnight(int i, int j){
    for(int k=0; k<8; ++k){
        int ni = i+kdi[k];
        int nj = j+kdj[k];
        // 범위 벗어나지 않고, 아직 잡힐 가능성 확인 안한 칸인 경우 이동
        if(ni>=1 && ni<=n && nj>=1 && nj<=m && board[ni][nj]==0){
            board[ni][nj] = -1;
        }
    }
}
int main(){
    cin >> n >> m;
    for(int t=1; t<=3; ++t){ // 1:Queen, 2:Knight, 3:Pawn
        cin >> a;
        for(int i=0; i<a; ++i){
            cin >> r >> c;
            board[r][c] = t;
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(board[i][j] == 1) mvQueen(i, j);
            else if(board[i][j] == 2) mvKnight(i, j);
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(board[i][j] == 0) cnt++; // 안전한 칸 세기
        }
    }
    cout << cnt;
    return 0;
}