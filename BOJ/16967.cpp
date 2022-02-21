// 16967번_배열 복원하기
#include <iostream>
#define MAX 601
using namespace std;
int n, m, x, y, arr[MAX][MAX];
void solve(){
    for(int i=0; i<n+x; ++i){
        for(int j=0; j<m+y; ++j){
            if(i>=x && j>=y) // 겹쳐져서 값이 바뀌거나 새로 추가된 부분
                arr[i][j] -= arr[i-x][j-y]; // 값 복원
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
int main(){
    cin >> n >> m >> x >> y;
    for(int i=0; i<n+x; ++i){
        for(int j=0; j<m+y; ++j){
            cin >> arr[i][j];
        }
    }
    solve();
    return 0;
}