// 2583번_영역 구하기
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MP make_pair
using namespace std;
int m, n, k, map[100][100];
int di[] = {0, 0, -1, 1}, dj[] = {-1, 1, 0, 0};
bool visited[100][100];
vector<int> ans;
void bfs(int y, int x){
    int area = 1;
    queue< pair<int, int> > q;
    q.push(MP(y, x));
    visited[y][x] = true;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni>=m || nj<0 || nj>=n) continue;
            if(map[ni][nj]==0 && !visited[ni][nj]){ // 이어진 영역을 전부 확인
                q.push(MP(ni, nj));
                visited[ni][nj] = true;
                area++; 
            }
        }
    }
    ans.push_back(area); // 현재 분리된 영역의 넓이
}
int main(){
    int cnt = 0;
    cin >> m >> n >> k;
    for(int x=0; x<k; ++x){
        int j1, j2, i1, i2;
        cin >> j1 >> i1 >> j2 >> i2;
        for(int i=i1; i<i2; i++){
            for(int j=j1; j<j2; j++){
                if(!map[i][j]) map[i][j] = 1; // 직사각형 영역 마킹
            }
        }
    }
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(map[i][j]==0 && !visited[i][j]){
                bfs(i, j); // 직사각형 제외하고 남은 영역의 넓이를 구함
                cnt++; // 분리되어 나누어지는 영역의 개수
            }
        }
    }
    cout << cnt << "\n";
    sort(ans.begin(), ans.end()); //
    for(int i=0; i<ans.size(); ++i) cout << ans[i] << " ";
    return 0;
}