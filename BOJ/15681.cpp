// 15681번_트리와 쿼리
#include <iostream>
#include <vector>
#define MAX 100000
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> vertex[MAX+1];
bool visited[MAX+1];
int v_cnt[MAX+1];
int n, r, q, u, v;
int dfs(int p){
    int cnt = 1; // 정점 p를 루트로 하는 서브트리에 p 자신도 포함됨
    visited[p] = true;
    for(int i=0; i<vertex[p].size(); ++i){
        int c = vertex[p][i]; // p와 연결된 정점
        if(!visited[c]) cnt += dfs(c);
    }
    v_cnt[p] = cnt;
    return cnt;
}
int main(){
    F_I;
    cin >> n >> r >> q;
    for(int i=0; i<n-1; ++i){
        cin >> u >> v;
        vertex[u].push_back(v);
        vertex[v].push_back(u);
    }
    v_cnt[r] = dfs(r); // 정점 r을 루트로 하는 서브트리의 정점 개수를 구함
    for(int i=0; i<q; ++i){
        cin >> u;
        cout << v_cnt[u] << "\n";
    }
    return 0;
}