// 16931번_겉넓이 구하기
#include <iostream>
using namespace std;
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
int n, m, ans, map[102][102];
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin >> map[i][j];
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            // 인접 칸의 블록 높이만큼 가려지는 부분을 제외한 나머지의 옆면 넓이를 구함
            for(int k=0; k<4; ++k){
                int ni = i+di[k];
                int nj = j+dj[k];
                int diff = map[i][j]-map[ni][nj];
                if(diff > 0) ans += diff;
            }
        }
    }
    ans += 2*n*m; // 윗면, 아랫면 넓이
    cout << ans;
    return 0;
}