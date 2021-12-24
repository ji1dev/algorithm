// 1405번_미친 로봇
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
double ans, prob[4];
bool visited[30][30];
void dfs(int i, int j, int cnt, double p){
    if(cnt > n){
        ans += p; // 이동 끝나면 확률 합산
        return;
    }
    for(int k=0; k<4; ++k){
        int ni = i+di[k], nj = j+dj[k];
        if(visited[ni][nj]) continue; // 재방문 하지 않을 때 이동경로 단순함
        visited[ni][nj] = true;
        dfs(ni, nj, cnt+1, p*prob[k]);
        visited[ni][nj] = false;
    }
}
int main(){
    cin >> n;
    for(int i=0; i<4; ++i){
        cin >> prob[i];
        prob[i] *= 0.01;
    }
    // 각 방향 14칸씩 이동 가능하므로 (15,15)에서 시작, 단순할 확률의 초기값은 1.0
    dfs(15, 15, 0, 1.0);
    cout.precision(10); // 10^-9 까지 허용
    cout << fixed << ans; // 소수부 기준 반올림
    return 0;
}