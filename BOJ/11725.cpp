// 11725번_트리의 부모 찾기
#include <iostream>
#include <vector>
#define MAX 100001 // OutOfBounds 주의...
using namespace std;
int n, a, b;
vector<int> node[MAX]; // idx번 노드에 연결된 노드들
int parent[MAX]; // idx번 노드의 부모 노드
bool visited[MAX]; // 방문기록
void dfs(int n){
    visited[n] = true;
    // n번 노드와 연결된 노드들을 확인
    for(int i=0; i<node[n].size(); ++i){
        int conn = node[n][i];
        if(!visited[conn]){
            // 1번 노드부터 트리를 따라 내려가므로 연결된 노드의 부모는 n번 노드
            parent[conn] = n;
            dfs(conn); 
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n-1; ++i){
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    dfs(1); // 1번 노드를 root라고 보고 dfs
    for(int i=2; i<=n; ++i){
        cout << parent[i] << "\n";
    }
    return 0;
}