// 13913번_숨바꼭질 4
#include <iostream>
#include <queue>
#include <vector>
#define MP make_pair
#define MAX 100000
using namespace std;
int n, k, ans, prev_pos[MAX+1];
bool visited[MAX+1];
queue< pair<int, int> > q;
vector<int> path;
void bfs(){
    visited[n] = true;
    q.push(MP(n, 0));
    while(!q.empty()){
        int x = q.front().first; // 현재 위치
        int sec = q.front().second; // 소요 시간
        q.pop();
        if(x == k){
            int pos = k; // 현재 위치(=목적지)
            while(pos != n){ // 탐색 시작 위치에 도착할 때 까지 반복
                path.push_back(pos);
                pos = prev_pos[pos]; // 현재 위치로 이동하기 전 위치
            }
            path.push_back(pos);
            ans = sec; // 동생 찾는 가장 빠른 시간
            return;
        }
        if(x-1>=0 && !visited[x-1]){
            visited[x-1] = true; // 방문 처리
            prev_pos[x-1] = x; // 새 위치로 이동하기 전 위치를 저장
            q.push(MP(x-1, sec+1)); // 새 위치 큐에 push
        }
        if(x+1<=MAX && !visited[x+1]){
            visited[x+1] = true;
            prev_pos[x+1] = x;
            q.push(MP(x+1, sec+1));
        }
        if(x*2<=MAX && !visited[x*2]){
            visited[x*2] = true;
            prev_pos[x*2] = x;
            q.push(MP(x*2, sec+1));
        }
    }
}
int main(){
    cin >> n >> k;
    bfs();
    cout << ans << "\n";
    int size = path.size();
    for(int i=0; i<size; ++i) cout << path[size-i-1] << " ";
    return 0;
}