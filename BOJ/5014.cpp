// 5014번_스타트링크
#include <iostream>
#include <queue>
#define MP make_pair
using namespace std;
int F, S, G, U, D;
bool visited[1000001];
queue < pair<int, int> > q;
void process(int next, int cnt){
    // 건물 층 범위에 들어오고, 아직 방문하지 않은 층이면 큐에 해당 층을 push
    if(next>=1 && next<=F && !visited[next]){
        q.push(MP(next, cnt));
        visited[next] = true;
    }
}
void bfs(){
    q.push(MP(S, 0));
    visited[S] = true;
    while(!q.empty()){
        int current = q.front().first;
        int cnt = q.front().second;
        q.pop();
        // F층 도달시 버튼 누른 횟수 출력하고 return
        if(current == G){
            cout << cnt;
            return;
        }
        process(current+U, cnt+1); // 위로 올라가는 경우
        process(current-D, cnt+1); // 아래로 내려가는 경우
    }
    cout << "use the stairs"; // F층 도달 실패시
}
int main(){
    cin >> F >> S >> G >> U >> D;
    bfs();
    return 0;
}