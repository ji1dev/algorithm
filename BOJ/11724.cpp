// 11724번_연결 요소의 개수
#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;
vector<int> g[MAX];
bool visited[MAX];
void dfs(int u){
    visited[u] = true;
    for(int v=0; v<g[u].size(); ++v){
        if(!visited[g[u][v]])
            dfs(g[u][v]);
    }
}
int main(){
    int n, m, u, v, cnt=0;
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int u=1; u<=n; ++u){
        if(!visited[u]){
            dfs(u);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}