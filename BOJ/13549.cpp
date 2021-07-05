// 13549번_숨바꼭질 3
#include <iostream>
#include <deque>
#define MAX 100000
#define MP make_pair
using namespace std;
int n, k;
deque< pair<int, int> > dq; // 위치, 시간 pair
bool visited[MAX+1]; // MAX 범위 주의하기
void bfs0_1(){
    // 간선 가중치가 다르므로 (순간이동시 0, 그냥 이동시 1) 0-1 BFS를 사용할 수 있음
    dq.push_back(MP(n, 0));
    visited[n] = true;
    while(!dq.empty()){
        int x = dq.front().first; // 현재 위치 (가중치 가장 작은 값 -> 최소 시간으로 도달한 위치)
        int sec = dq.front().second;
        dq.pop_front();
        visited[x] = true;
        if(x == k){
            cout << sec;
            return;
        }
        if(x-1>=0 && !visited[x-1]) dq.push_back(MP(x-1, sec+1));
        if(x+1<=MAX && !visited[x+1]) dq.push_back(MP(x+1, sec+1));
        if(x*2<=MAX && !visited[x*2]) dq.push_front(MP(x*2, sec)); // 0초 걸리는 순간이동은 가장 앞에 push
    }
}
int main(){
    cin >> n >> k;
    bfs0_1();
    return 0;
}