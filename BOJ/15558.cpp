// 15558번_점프 게임
#include <iostream>
#include <queue>
#define MP make_pair
using namespace std;
int n, k, cnt, map[2][200002];
bool visited[2][200002];
queue< pair<int, int> > q; // 줄, 칸
void bfs(){
    q.push(MP(0, 0)); // 왼쪽 줄 첫 칸에서 시작
    visited[0][0] = true;
    while(!q.empty()){
        int s = q.size();
        while(s--){ // 같은 시간에 들어온 칸 체크
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(j >= n){
                cout << 1; // 게임을 클리어 할 수 있는 경우
                return;
            }
            if(map[i][j] == -1) continue; // 삭제된 칸이면 넘어감
            int ni[] = {i, i, !i}, nj[] = {j+1, j-1, j+k}; // 앞, 뒤, 다른 줄 k칸 앞
            for(int d=0; d<3; ++d){
                // 계산된 칸이 n번칸 이상이거나, 방문X && 안전한 칸인 경우 큐에 push
                if(nj[d]>=n || (!visited[ni[d]][nj[d]] && map[ni[d]][nj[d]]==1)){
                    visited[ni[d]][nj[d]] = true;
                    q.push(MP(ni[d], nj[d]));
                }
            }
        }
        map[0][cnt] = -1;
        map[1][cnt] = -1;
        cnt++; // 매 시간마다 각 줄의 첫 칸이 사라짐
    }
    cout << 0; // 게임을 클리어 할 수 없는 경우
}
int main(){
    cin >> n >> k;
    for(int i=0; i<2; ++i){
        for(int j=0; j<n; ++j){
            scanf("%1d", &map[i][j]);
        }
    }
    bfs();
    return 0;
}