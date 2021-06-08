// 1389번_케빈 베이컨의 6단계 법칙
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int n, m, path[101][101];
void f(){
    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(i == j) continue; // 자기 자신은 건너뜀
                else if(path[i][k] && path[k][j]){ // i->k, k->j 경로 있는 경우
                    if(path[i][j] == 0) // i->j 직접 경로 없으면 k거쳐감
                        path[i][j] = path[i][k]+path[k][j];
                    else{ // i->j 직접 경로 있으면 i->j or i->k->j중 작은 쪽 선택
                        path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
                    }
                }
            }
        }
    }
}
int main(){
    int a, b, sum, ans, min_k;
    min_k = INT_MAX;
    cin >> n >> m;
    for(int i=1; i<=m; ++i){
        cin >> a >> b;
        path[a][b] = 1;
        path[b][a] = 1;
    }
    f();
    for(int i=1; i<=n; ++i){
        sum = 0;
        // 각 사람마다 케빈 베이컨의 수를 구하고 가장 작은 값을 가지는 사람을 찾음
        for(int j=1; j<=n; ++j) 
            sum += path[i][j];
        if(min_k > sum){
            min_k = sum;
            ans = i;
        }
    }
    cout << ans;
    return 0;
}