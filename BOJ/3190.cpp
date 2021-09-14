// 3190번_뱀
#include <iostream>
#include <deque>
#define MP make_pair
using namespace std;
int n, k, l, di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1}; // top, right, bottom, left
pair<int, int> rotation[101];
deque< pair<int, int> > snake;
bool visited[101][101], apple[101][101];
void play(){
    int time = 0, ridx = 0, way = 1; // 처음 방향은 오른쪽
    snake.push_back(MP(0, 0)); // (0, 0)에서 게임 시작
    visited[0][0] = true;
    while(1){
        time++;
        int ni = snake.front().first+di[way];
        int nj = snake.front().second+dj[way];
        if(ni<0 || ni>=n || nj<0 || nj>=n || visited[ni][nj]){ // 벽 또는 자기 몸과 부딪히면 종료
            cout << time;
            return;
        }
        snake.push_front(MP(ni, nj)); // 머리를 다음칸에 위치시킴
        visited[ni][nj] = true;
        if(apple[ni][nj]){ // 사과 있으면 칸에 있는 사과 없어지고 꼬리 그대로
            apple[ni][nj] = false;
        }
        else{ // 사과 없으면 몸길이 줄여서 꼬리칸을 비워줌
            int ti = snake.back().first;
            int tj = snake.back().second;
            snake.pop_back();
            visited[ti][tj] = false;
        }
        if(time == rotation[ridx].first){ // 마지막에 방향 변환
            if(rotation[ridx].second == 'L') way = (way-1)>=0 ? way-1 : 3;
            else way = (way+1)<=3 ? way+1 : 0;
            ridx++;
        }
    }
}
int main(){
    cin >> n >> k;
    for(int i=0; i<k; ++i){
        int r, c;
        cin >> r >> c;
        apple[r-1][c-1] = true;
    }
    cin >> l;
    for(int i=0; i<l; ++i){
        int x;
        char c;
        cin >> x >> c; // 회전 타이밍, 회전 방향
        rotation[i] = MP(x, c);
    }
    play();
    return 0;
}