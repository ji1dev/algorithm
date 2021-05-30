// 1780번_종이의 개수
#include <iostream>
using namespace std;
int n, paper[2187][2187], ans[3];
bool flag;

void dc(int row, int col, int num){
    int current = paper[row][col];
    flag = true;
    for(int i=row; i<row+num; ++i){ // row ~ row+num 은 시작지점~종료지점
        for(int j=col; j<col+num; ++j){
            if(paper[i][j] != current){ // 현재 범위의 첫 값과 다른 값이 하나라도 있으면
                flag = false; // 분할 필요
                break;
            }
        }
    }
    if(flag){
        // ans[0]= -1개수, [1]= 0개수, [2]= 1개수 count
        ans[current+1]++;
    }
    else{
        // 같은 크기의 9개의 종이로 분할함 (가로, 세로 길이는 1/3)
        num /= 3;
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                // 9분할된 각 영역의 row, col 시작점 계산해서 함수 반복 호출
                dc(row+num*i, col+num*j, num);
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> paper[i][j];
        }
    }
    dc(0, 0, n);
    for(int i=0; i<3; ++i) cout << ans[i] << "\n";
    return 0;
}