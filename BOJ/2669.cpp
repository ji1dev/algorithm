// 2669번_직사각형 네개의 합집합의 면적 구하기
#include <iostream>
using namespace std;
int area;
bool visited[101][101];
int main(){
    for(int k=0; k<4; ++k){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=y1; i<y2; ++i){
            for(int j=x1; j<x2; ++j){
                if(!visited[i][j]) visited[i][j] = true;
            }
        }
    }
    for(int i=0; i<100; ++i){
        for(int j=0; j<100; ++j){
            if(visited[i][j]) area++;
        }
    }
    cout << area;
    return 0;
}