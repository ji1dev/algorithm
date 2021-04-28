// 1260번_DFS와 BFS
#include <iostream>
#include <queue>
using namespace std;
int n, m, v;
int arr[1001][1001];
bool visited[1001];
void dfs(int v){
    cout << v << " ";
    visited[v] = true; // 정점 v를 방문 처리
    for(int i=1; i<=n; ++i){
        // 정점 v에서 i로 가는 간선이 있고, 정점 i를 방문하지 않은 경우
        if(arr[v][i] && !visited[i]) dfs(i);
    }
}
void bfs(int v){
    queue <int> q;
    q.push(v); // 시작 정점을 큐에 push
    while(!q.empty()){
        // 큐가 빌 때 까지 front에 있는 정점을 출력 및 pop
        int current = q.front();
        visited[current] = true;
        cout << current << " ";
        q.pop();
        for(int i=1; i<=n; ++i){
            // 현재 정점에서 i로 가는 간선이 있고, 정점 i를 방문하지 않은 경우
            if(arr[current][i] && !visited[i]){
                // 큐에 push, 방문 처리
                q.push(i);
                visited[i] = true; 
            }
        }
    }
}
int main(){
    int src, dst;
    cin >> n >> m >> v;
    for(int i=0; i<m; ++i){
        cin >> src >> dst;
        // src, dst 정점 사이 간선을 설정
        arr[src][dst] = 1;
        arr[dst][src] = 1;
    }
    dfs(v); cout << "\n"; // 시작 정점v
    for(int i=1; i<=n; ++i) visited[i] = false; // 방문 정점 초기화
    bfs(v); cout << "\n";
    return 0;
}