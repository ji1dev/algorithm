// 1074번_Z
#include <iostream>
#include <math.h>
using namespace std;
int n, r, c, visitCnt;
void Z(int x, int y, int length){
    // 각 사분면을 재귀적으로 방문하며 r행 c열을 몇 번째로 방문하는지 찾음
    // 현재 사분면에 r행 c열이 없다면 다음 사분면으로 바로 넘어감
    // 이 때 해당 사분면 내의 칸 개수만큼 count 더해주기
    if(x==c && y==r){
        // 현재 좌표가 r행 c열이면 답 출력 후 종료
        cout << visitCnt;
        exit(0);
    }
    if(length == 1){
        // 현재 사분면의 길이가 1이면 더 이상 쪼갤 수 없으므로 count++ 후 탈출
        visitCnt++;
        return;
    }
    if(!(x<=c && c<x+length && y<=r && r<y+length)){
        // 현재 사분면에 (c, r)이 없으면 사분면 내부의 칸 수만큼 count를 증가시키고 탈출
        visitCnt += pow(length, 2);
        return;
    }
    Z(x, y, length/2); // 1사분면
    Z(x+length/2, y, length/2); //2사분면
    Z(x, y+length/2, length/2); // 3사분면
    Z(x+length/2, y+length/2, length/2); // 4사분면
}
int main(){
    cin >> n >> r >> c;
    Z(0, 0, pow(2, n)); // (0, 0)부터 시작
    return 0;
}