// 16926번_배열 돌리기 1
#include <iostream>
using namespace std;
int n, m, r, arr[301][301];
void rotateArr(){
    int si = 0, sj = 0; // 시작 기준점
    int ei = n-1, ej = m-1; // 끝 기준점
    while(si<ei && sj<ej){ // 기준점이 겹치지 않으면 한 칸씩 내부로 들어가서 돌림
        int tmp = arr[si][sj];
        for(int j=sj; j<ej; ++j) arr[si][j] = arr[si][j+1]; // top
        for(int i=si; i<ei; ++i) arr[i][ej] = arr[i+1][ej]; // right
        for(int j=ej; j>sj; --j) arr[ei][j] = arr[ei][j-1]; // bottom
        for(int i=ei; i>si; --i) arr[i][sj] = arr[i-1][sj]; // left
        arr[si+1][sj] = tmp;
        si++;
        sj++;
        ei--;
        ej--;
    }
}
int main(){
    cin >> n >> m >> r;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> arr[i][j];
        }
    }
    while(r--) rotateArr();
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}