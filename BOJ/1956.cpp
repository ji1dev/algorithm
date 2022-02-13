// 1956번_운동
#include <iostream>
#include <algorithm>
#define INF 987654321
#define MAX 401
using namespace std;
int n, m, result[MAX], path[MAX][MAX];
void solve(){
    for(int k=1; k<=n; ++k){ // Floyd
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(i == j) continue;
                if(path[i][k] && path[k][j])
                    path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
            }
        }
    }
    int dist = INF;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            // i->j, j->i 최단거리가 존재하면 사이클이 존재하므로 사이클의 거리 합의 최솟값을 갱신
            if(path[i][j]!=INF && path[j][i]!=INF)
                dist = min(dist, path[i][j]+path[j][i]);
        }
    }
    // 운동 경로를 찾을 수 없는 경우 -1 출력
    cout << (dist!=INF ? dist : -1);
}
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            path[i][j] = INF;
        }
    }
    for(int i=0, a, b, c; i<m; ++i){
        cin >> a >> b >> c; // a->b까지 거리 c
        path[a][b] = c;
    }
    solve();
    return 0;
}