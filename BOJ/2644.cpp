// 2644번_촌수계산
#include <iostream>
#include <queue>
#define MP make_pair
using namespace std;
int n, start, target, m, graph[100][100];
bool visited[100];
void bfs(){
    queue< pair<int, int> > q;
    q.push(MP(start, 0));
    while(!q.empty()){
        int p = q.front().first; // 사람 번호
        int c = q.front().second; // 시작 사람 기준 촌수
        q.pop();
        if(p == target){ // 촌수 구하려는 사람에 도달하면 출력 후 return
            cout << c;
            return;
        }
        for(int i=1; i<=n; ++i){
            // i번째 사람과 직접 관계가 있고, 아직 방문하지 않았다면 큐에 push (촌수+1)
            if(graph[p][i]==1 && !visited[i]){
                visited[i] = true;
                q.push(MP(i, c+1));
            }
        }
    }
    cout << "-1";
}

int main(){
    int p1, p2;
    cin >> n >> start >> target >> m;
    for(int i=0; i<m; ++i){
        cin >> p1 >> p2;
        graph[p1][p2] = 1;
        graph[p2][p1] = 1;
    }
    bfs();
    return 0;
}