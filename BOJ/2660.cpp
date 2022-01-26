// 2660번_회장뽑기
#include <iostream>
#include <algorithm>
#define INF 987654321
#define MAX 51
using namespace std;
int n, a, b, path[MAX][MAX];
void solve(){
    // 플로이드 와샬 알고리즘으로 최소비용 구함
    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(i == j) continue;
                if(path[i][k] && path[k][j]){
                    path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
                }
            }
        }
    }
    // 각 회원마다 최대 점수와 회장(회원들 중에서 점수가 가장 작은 사람)으로 선출 가능한 점수를 구함
    int pts[MAX] = {0, }, ans_pts = INF, cnt = 0;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            pts[i] = max(pts[i], path[i][j]);
        }
        ans_pts = min(ans_pts, pts[i]);
    }
    // 회장 가능한 사람 수 구하고 결과 출력
    for(int i=1; i<=n; ++i){
        if(pts[i] == ans_pts) cnt++;
    }
    cout << ans_pts << " " << cnt << "\n";
    for(int i=1; i<=n; ++i){
        if(pts[i] == ans_pts) cout << i << " ";
    }
}
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(i != j) path[i][j] = INF;
        }
    }
    while(a!=-1 && b!=-1){
        cin >> a >> b;
        path[a][b] = path[b][a] = 1;
    }
    solve();
    return 0;
}