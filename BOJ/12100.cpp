// 12100번_2048 (Easy)
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
int n, ans, board[21][21];
void moveBlockLeft(){ // 왼쪽으로 이동하는 로직만 구현 후 보드를 회전시키며 재활용
    queue<int> q;
    for(int i=0; i<n; ++i){ // 한 행씩 왼쪽으로 이동시킴
        for(int j=0; j<n; ++j){
            if(board[i][j]){
                q.push(board[i][j]);
                board[i][j] = 0; // 큐에 블록의 값을 넣고 빈 칸으로 바꿈
            }
        }
        int mj = 0;
        while(!q.empty()){
            int value = q.front();
            q.pop();
            if(board[i][mj] == 0) board[i][mj] = value; // 빈 칸이면 바로 블록 이동
            else{
                if(board[i][mj] == value) board[i][mj] *= 2; // 같은 블록이면 합침
                else board[i][mj+1] = value; // 다른 블록이면 한 칸 오른쪽으로 이동
                mj++;
            }
        }   
    }
}
void rotateBoard(){
    int rtmp[21][21] = {0, };
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            rtmp[i][j] = board[n-1-j][i]; // 시계방향 90도 회전
        }
    }
    memcpy(board, rtmp, sizeof(rtmp));
}
void dfs(int cnt){
    if(cnt == 5){ // 얻을 수 있는 최대 블록의 값 갱신
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                ans = max(ans, board[i][j]);
            }
        }
        return;
    }
    for(int k=0; k<4; ++k){
        int tmp[21][21] = {0, };
        memcpy(tmp, board, sizeof(board)); // 임시 보드에 복사
        moveBlockLeft(); // 블록 왼쪽으로 이동하고 가능하면 합치기
        dfs(cnt+1);
        memcpy(board, tmp, sizeof(tmp)); // 원본 보드로 롤백
        rotateBoard(); // 보드 회전
    }
    
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> board[i][j];
        }
    }
    dfs(0); // 이동 횟수
    cout << ans;
    return 0;
}