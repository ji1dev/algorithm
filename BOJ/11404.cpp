// 11404번_플로이드 
#include <iostream>
#include <algorithm>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321
using namespace std;
int n, m, path[101][101];
void floyd(){
    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(i == j) continue;
                else if(path[i][k] && path[k][j]){
                    // i->k, k->j 경로 있는 경우 i->j 직접 갈 수 없으면 k를 거쳐가고,
                    // 아니면 직접 가거나 k를 거쳐가는 경로 중 낮은 비용인 경로를 선택
                    if(path[i][j] == 0){
                        path[i][j] = path[i][k]+path[k][j];
                    }
                    else{
                        path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
                    }
                }
            }
        }
    }
}
int main(){
    F_IO;
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(i != j) path[i][j] = INF; // 자기 자신으로 가는 경로 제외 INF로 초기화
        }
    }
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c; // a에서 b도시로 가는 비용 c
        if(path[a][b]>0 && path[a][b]>c){
            path[a][b] = c;
        }
    }
    floyd();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(path[i][j] == INF) cout << "0 ";
            else cout << path[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}