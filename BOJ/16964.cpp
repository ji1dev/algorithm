// 16964번_DFS 스페셜 저지
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> g[MAX];
bool isDiff, visited[MAX];
int n, cnt, tr[MAX], seq[MAX];
void dfs(int v){
    if(tr[cnt] != v){ // 주어진 방문 순서와 다른 정점인 경우
        isDiff = true;
        return;
    }
    visited[v] = true;
    for(int i=0; i<g[v].size(); ++i){
        int next = g[v][i];
        if(visited[next]) continue;
        cnt++;
        dfs(next);
    }
}
bool cmp(int v, int u){
    return seq[v] < seq[u];
}
int main(){
    F_IO;
    cin >> n;
    for(int i=0; i<n-1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // DFS로 방문하는 정점을 순서대로 기록하는 tr배열, 해당 정점을 몇번째로 방문하는지 기록하는 seq배열
    for(int i=0; i<n; ++i){
        cin >> tr[i];
        seq[tr[i]] = i;
    }
    // 같은 depth의 정점들은 방문 순서가 바뀌어도 올바른것으로 판단하기위해 
    // 입력된 방문 순서에 따라 각 정점에 대한 인접 정점들의 순서를 조정함
    for(int i=1; i<=n; ++i){
        sort(g[i].begin(), g[i].end(), cmp);
    }
    dfs(1);
    if(isDiff) cout << 0;
    else cout << 1;
    return 0;
}