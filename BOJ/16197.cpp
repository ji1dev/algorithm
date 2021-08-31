// 16197번_두 동전
#include <iostream>
#include <queue>
#include <vector>
#define MP make_pair
using namespace std;
int n, m, di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};;
char map[21][21];
bool visited[21][21][21][21]; // 동전1, 동전2
vector< pair<int, int> > v;
queue< pair< pair< pair<int, int>, pair<int, int> >, int > > q; // 동전1, 동전2, 버튼 클릭 횟수
int check(int i1, int j1, int i2, int j2){
    // return 0: 둘 다 안떨어짐, 1: 하나만 떨어짐, 2: 둘 다 떨어짐
    if(i1<0 || i1>=n || j1<0 || j1>=m){
        if(i2<0 || i2>=n || j2<0 || j2>=m) return 2;
        else return 1; 
    }
    else{
        if(i2<0 || i2>=n || j2<0 || j2>=m) return 1;
        else return 0;
    }
}
void bfs(){
    q.push(MP(MP(v[0], v[1]), 0));
    visited[v[0].first][v[0].second][v[1].first][v[1].second] = true;
    while(!q.empty()){
        int i1 = q.front().first.first.first;
        int j1 = q.front().first.first.second;
        int i2 = q.front().first.second.first;
        int j2 = q.front().first.second.second;
        int cnt = q.front().second;
        q.pop();
        if(cnt > 10) break;
        for(int k=0; k<4; ++k){
            int ni1 = i1+di[k];
            int nj1 = j1+dj[k];
            int ni2 = i2+di[k];
            int nj2 = j2+dj[k];
            int res = check(ni1, nj1, ni2, nj2);
            if(res == 1){
                if(cnt+1 <= 10) cout << cnt+1; // 10회 이내로 떨어지면 결과 출력
                else cout << -1;
                return;
            }
            else if(res == 2) continue; // 둘 다 떨어지면 넘어감
            if(map[ni1][nj1]=='#' && map[ni2][nj2]=='#') continue; // 둘 다 벽이면 넘어감
            if(map[ni1][nj1] == '#'){ // 벽 만나면 한 칸 롤백
                ni1 -= di[k];
                nj1 -= dj[k];
            }
            else if(map[ni2][nj2] == '#'){
                ni2 -= di[k];
                nj2 -= dj[k];
            }
            if(visited[ni1][nj1][ni2][nj2]) continue;
            q.push(MP(MP(MP(ni1, nj1), MP(ni2, nj2)), cnt+1));
            visited[ni1][nj1][ni2][nj2] = true;
        }
    }
    cout << -1;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            scanf("%1s", &map[i][j]);
            if(map[i][j] == 'o') v.push_back(MP(i, j));
        }
    }
    bfs();
    return 0;
}