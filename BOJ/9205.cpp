// 9205번_맥주 마시면서 걸어가기
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <memory.h>
#define MP make_pair
using namespace std;
int t, n, hx, hy, tx, ty, x, y;
bool visited[100]; // 편의점 방문 기록
vector< pair<int, int> > cvs;
queue< pair<int, int> > q;
void bfs(){
    bool flag = false;
    q.push(MP(hx, hy)); // 집 위치에서 시작
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<cvs.size(); ++i){
            // 편의점까지 맨해튼 거리가 1000이하이고, 방문하지 않았으면 큐에 push
            if((abs(cx-cvs[i].first) + abs(cy-cvs[i].second))<=1000 && !visited[i]){
                visited[i] = true;
                q.push(MP(cvs[i].first, cvs[i].second));
            }
        }
        // 목적지까지 맨해튼 거리가 1000이하이면 바로 갈 수 있음
        if((abs(cx-tx) + abs(cy-ty))<=1000){
            flag = true;
        }
    }
    if(flag) cout << "happy\n";
    else cout << "sad\n";
}
int main(){
    cin >> t;
    while(t--){
        memset(visited, false, sizeof(visited));
        cin >> n; // 편의점 개수
        cin >> hx >> hy; // home coordinates
        for(int i=0; i<n; ++i){
            int x, y;
            cin >> x >> y; // cvs coordinates
            cvs.push_back(MP(x, y));
        }
        cin >> tx >> ty; // target coordinates
        bfs();
        cvs.clear(); // 편의점 목록 초기화
    }
    return 0;
}