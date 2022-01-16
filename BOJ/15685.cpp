// 15685번_드래곤 커브
#include <iostream>
#include <vector>
#define MAX 101
using namespace std;
bool map[MAX][MAX];
int n, dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int count(){
    // 1x1 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수 count
    int ans = 0;
    for(int i=0; i<MAX; ++i){
        for(int j=0; j<MAX; ++j){
            if(map[i][j] && map[i+1][j] && map[i+1][j+1] && map[i][j+1]) ans++;
        }
    }
    return ans;
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        vector<int> v; // 각 드래곤 커브를 구성하는 선분들의 방향 정보 저장
        int x, y, d, g, idx = -1;
        cin >> x >> y >> d >> g;
        map[x][y] = true; // 시작 점
        v.push_back(d); // 시작 방향
        while(g--){
            // 각 세대마다 기존 드래곤 커브를 시계 방향으로 90도 회전시킨뒤 커브에 속한 각 선분의 방향을 기록
            // 끝 점 기준 회전 후 끝 점에 붙이므로 기존 커브를 구성하는 선분들을 끝 점에서부터 역순으로 기록함
            // 이 때 각 선분의 방향은 기존 방향에서 반시계 방향으로 90도 회전시킨 결과와 같음
            for(int j=v.size()-1; j>=0; --j){
                v.push_back((v[j]+1)%4);
                idx++;
            }
            
        }
        for(int k=0; k<v.size(); ++k){ // 새 커브 표시
            x += dx[v[k]];
            y += dy[v[k]];
            map[x][y] = true;
        }
    }
    cout << count();
    return 0;
}