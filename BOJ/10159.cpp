// 10159번_저울
#include <iostream>
#include <algorithm>
#define MAX 101
#define INF 987654321
using namespace std;
int n, m;
bool path[MAX][MAX];
void solve(){
    for(int k=1; k<=n; ++k){ // Floyd–warshall
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(i == j) continue;
                if(path[i][k] && path[k][j])
                    path[i][j] = true; // 경로 존재 여부만 체크해도 되므로 boolean값으로 저장
            }
        }
    }
    for(int i=1; i<=n; ++i){ // i->j 또는 j->i 경로 존재하면 물건 i와 j의 비교 가능한 것
        int res = n-1; // 자기 자신 제외
        for(int j=1; j<=n; ++j){
            if(path[i][j] || path[j][i]) res--;
        }
        cout << res << "\n";
    }
}
int main(){
    cin >> n >> m;
    for(int i=0, a, b; i<m; ++i){
        cin >> a >> b; // 일부 물건 쌍의 비교 결과
        path[a][b] = true;
    }
    solve();
    return 0;
}