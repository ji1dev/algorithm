// 17129번_윌리암슨수액빨이딱따구리가 정보섬에 올라온 이유
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define MP make_pair
#define MAX 3001
using namespace std;
int n, m, map[MAX][MAX], visited[MAX][MAX];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
queue<pair<int, int> > q;
void solve(){
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(map[i][j]==3 || map[i][j]==4 || map[i][j]==5){
            cout << "TAK\n" << visited[i][j];
            return;
        }
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=n || nj<0 || nj>=m || visited[ni][nj]) continue;
            if(map[ni][nj] == 1) continue;
            visited[ni][nj] = visited[i][j]+1;
            q.push(MP(ni, nj));
        }
    }
    cout << "NIE";
}
int main(){
    string s;
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> s;
        for(int j=0; j<m; ++j){
            // 격자의 각 값 입력받을때 공백없이 들어오는 경우 문자열로 받아서 뿌려주는것이 더 빠름
            map[i][j] = s[j]-'0';
            if(map[i][j] == 2) q.push(MP(i, j));
        }
        // for(int j=0; j<m; ++j){
        //     scanf("%1d", &map[i][j]); // scanf 때문에 TLE남
        //     if(map[i][j] == 2) q.push(MP(i, j));
        // }
    }
    solve();
    return 0;
}