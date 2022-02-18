// 2617번_구슬 찾기
#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;
int n, m, c, ans;
bool path[MAX][MAX];
void solve(){
    for(int k=1; k<=n; ++k){ // Floyd로 경로 존재 여부 체크
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(i == j) continue;
                if(path[i][k] && path[k][j])
                    path[i][j] = true;
            }
        }
    }
    for(int i=1; i<=n; ++i){
        int r1 = 0, r2 = 0;
        for(int j=1; j<=n; ++j){
            if(i == j) continue;
            if(path[i][j]) r1++; // 무거운 구슬 개수
            else if(path[j][i]) r2++; // 가벼운 구슬 개수
        }
        if(r1>=c || r2>=c) ans++; // 무게 비교 결과, 중간값이 될 수 없는 구슬 count
    }
    cout << ans;
}
int main(){
    cin >> n >> m;
    for(int i=0, a, b; i<m; ++i){
        cin >> a >> b;
        path[a][b] = true;
    }
    c = (n+1)/2; // 중간값
    solve();
    return 0;
}