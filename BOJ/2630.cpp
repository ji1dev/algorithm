// 2630번_색종이 만들기
#include <iostream>
using namespace std;
int n, white, blue, map[128][128];
void dc(int x1, int x2, int y1, int y2){
    int current = map[x1][y1]; // 각 구역의 첫 블럭 색깔
    for(int x=x1; x<x2; ++x){
        for(int y=y1; y<y2; ++y){
            if((current==0 && map[x][y]!=0) || (current==1 && map[x][y]!=1)){
                dc(x1, (x1+x2)/2, y1, (y1+y2)/2); // 좌상단
                dc((x1+x2)/2, x2, y1, (y1+y2)/2); // 우상단
                dc(x1, (x1+x2)/2, (y1+y2)/2, y2); // 좌하단
                dc((x1+x2)/2, x2, (y1+y2)/2, y2); // 우하단
                return;
            }
        }
    }
    if(current == 0) white++;
    else if(current == 1) blue++;
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> map[i][j];
        }
    }
    dc(0, n, 0, n); // x시작, x종료, y시작, y종료 좌표
    cout << white << "\n" << blue;    
    return 0;
}