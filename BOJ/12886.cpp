// 12886번_돌 그룹
#include <iostream>
#include <queue>
#define MP make_pair
using namespace std;
int a, b, c, sum;
bool visited[1501][1501]; // visited[i][j] = 돌 i개, j개를 만들 수 있는지 기록
void solve(int x, int y){
    queue<pair<int, int> > q;
    q.push(MP(x, y));
    visited[x][y] = true;
    while(!q.empty()){
        int r1 = q.front().first;
        int r2 = q.front().second;
        // 돌 a, b, c 중 2개만 정해지면 나머지 하나는 자동으로 결정됨
        int tmp[] = {r1, r2, sum-r1-r2};
        q.pop();
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                if(tmp[i] < tmp[j]){ 
                    int n1 = tmp[i]+tmp[i]; // 돌의 개수가 작은 쪽
                    int n2 = tmp[j]-tmp[i]; // 돌의 개수가 큰 쪽
                    if(visited[n1][n2]) continue;
                    visited[n1][n2] = true;
                    q.push(MP(n1, n2));
                }
            }
        }
    }
}
int main(){
    cin >> a >> b >> c; // 1 <= a, b, c <= 500
    sum = a+b+c;
    if(sum%3){
        cout << 0;
        return 0;
    }
    solve(a, b);
    // 돌 3개를 같은 개수로 만들 수 있는지 확인
    if(visited[sum/3][sum/3]) cout << 1;
    else cout << 0;
    return 0;
}