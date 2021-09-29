// 16972번_배열 돌리기 2
#include <iostream>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, m, r, a[301][301];
void rotateArray(){
    int si = 0, sj = 0; // 회전시킬 사각형 모양의 시작, 종료 좌표
    int ei = n-1, ej = m-1;
    while(si<ei && sj<ej){ // 시작, 종료 좌표가 역전되면 탈출
        // 돌려야하는 횟수를 현재 사각형의 칸 개수와 모듈러 연산한 만큼만 회전
        // 현재 사각형에 대해 (r%len)회 회전시키는 것
        int len = (ei-si+1)*2+(ej-sj+1)*2-4;
        for(int t=0; t<r%len; ++t){
            int first = a[si][sj]; // 시작 위치의 원소
            for(int j=sj; j<ej; ++j){
                a[si][j] = a[si][j+1]; // top 행 원소 왼쪽으로 이동
            }
            for(int i=si; i<ei; ++i){
                a[i][ej] = a[i+1][ej]; // right 열 위쪽으로 이동
            }
            for(int j=ej; j>sj; --j){
                a[ei][j] = a[ei][j-1]; // bottom 행 원소 오른쪽으로 이동
            }
            for(int i=ei; i>si; --i){
                a[i][sj] = a[i-1][sj]; // left 열 아래쪽으로 이동 
            }
            a[si+1][sj] = first;
        }
        si++; // 사각형 모양 한 칸 안쪽으로 들여오기
        sj++;
        ei--;
        ej--;
    }
}
int main(){
    F_IO;
    cin >> n >> m >> r;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> a[i][j];
        }
    }
    rotateArray();
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}