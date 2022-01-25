// 3709번_레이저빔은 어디로
#include <iostream>
#include <memory.h>
#define MAX 52
using namespace std;
int t, n, r, li, lj;
int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1}; // 북쪽 기준 CW
bool map[MAX][MAX]; // 우향우 거울이 배치된 위치
void solve(int i, int j, int d){
    if(i==0 || i==(n+1) || j==0 || j==(n+1)){
        cout << i << " " << j << "\n";
        return;
    }
    int nd = (d+1)%4; // 우향우
    if(map[i][j]) solve(i+di[nd], j+dj[nd], nd); // 거울 칸
    else solve(i+di[d], j+dj[d], d); // 일반 칸

}
int main(){
    cin >> t;
    while(t--){
        cin >> n >> r;
        memset(map, false, sizeof(map));
        for(int k=0, i, j; k<r; ++k){
            cin >> i >> j;
            map[i][j] = true;
        }
        cin >> li >> lj;
        if(li == 0) solve(li+1, lj, 2); // 남쪽
        else if(li == n+1) solve(li-1, lj, 0); // 북쪽
        else if(lj == 0) solve(li, lj+1, 1); // 동쪽
        else if(lj == n+1) solve(li, lj-1, 3); // 서쪽
    }
    return 0;
}