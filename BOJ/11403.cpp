// 11403번_경로 찾기
#include <iostream>
#include <memory.h>
using namespace std;
int n;
int graph[101][101];
bool visited[101];
void DFS(int i){
    for(int j=1; j<=n; ++j){
        // 정점 i->j 경로 존재하고 정점 j아직 방문 안한 경우
        if(graph[i][j]==1 && !visited[j]){
            visited[j] = true;
            DFS(j);
        }
    }
}
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin >> graph[i][j];
        }
    }
    for(int i=1; i<=n; ++i){
        // 정점 i ... n 에서 다른 정점으로 가는 경로가 있는지 확인
        // 다른 정점을 거쳐가는 경우 또한 경로가 존재하는 것
        memset(visited, false, sizeof(visited));
        DFS(i);
        for(int x=1; x<=n; ++x){
            cout << visited[x] << " ";
        }
        cout << "\n";
    }
    return 0;
}