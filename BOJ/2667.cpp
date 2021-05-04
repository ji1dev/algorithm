// 2667번_단지번호붙이기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, cnt;
int dx[] = {0, 1, 0, -1}; // top, right, bottom, left
int dy[] = {-1, 0, 1, 0};
int m[26][26];
int houseCnt;
vector<int> house;
void dfs(int i, int j){
    int nx, ny;
    m[i][j] = 0; // 방문 처리
    houseCnt++; // 현재 단지 내 집의 수 ++
    for(int l=0; l<4; ++l){
        nx = i+dx[l];
        ny = j+dy[l];
        // top, right, bottom, left중 범위 벗어나는 좌표는 건너 뜀
        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        // 새 좌표의 집을 아직 방문하지 않았으면 다시 dfs호출
        if(m[nx][ny] == 1) dfs(nx, ny);
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            scanf("%1d", &m[i][j]);
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(m[i][j] == 1){
                houseCnt = 0;
                dfs(i, j);
                house.push_back(houseCnt);
            }
        }
    }
    sort(house.begin(), house.end());
    cout << house.size() << "\n";
    for(int i=0; i<house.size(); ++i){
        cout << house[i] << "\n";
    }
    return 0;
}