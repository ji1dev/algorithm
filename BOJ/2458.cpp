// 2458번_키 순서
#include <iostream>
#include <algorithm>
#define MAX 501
#define INF 987654321
using namespace std;
int n, m, ans, path[MAX][MAX], inout[MAX];
void solve(){
    for(int k=1; k<=n; ++k){ // Floyd
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(i == j) continue;
                if(path[i][k] && path[k][j]){
                    path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
                }
            }
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            // i->j 경로 존재시 i보다 큰 인원, j보다 작은 인원을 count
            if(path[i][j] != INF){
                inout[i]++; // i보다 큰 인원
                inout[j]++; // j보다 작은 인원
            }
        }
    }
    for(int i=1; i<=n; ++i){
        if(inout[i] == n-1) ans++; // 본인 제외 (n-1)명 파악 되는 경우
    }
    cout << ans;
}
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            path[i][j] = INF;
        }
    }
    for(int i=0, a, b; i<m; ++i){
        cin >> a >> b;
        path[a][b] = 1;
    }
    solve(); // 본인 키 순서는 본인보다 작은 인원과 큰 인원을 모두 파악하면 알 수 있음
    return 0;
}