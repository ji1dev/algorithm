// 6118번_숨바꼭질
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 20001
#define MP make_pair
using namespace std;
int n, m;
vector<int> g[MAX];
void solve(){
    queue<int> q;
    int max_d = 0, visited[MAX] = {0, };
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int k=0; k<g[cur].size(); ++k){
            int next = g[cur][k];
            if(visited[next]) continue;
            visited[next] = visited[cur]+1;
            max_d = max(max_d, visited[next]); // 가장 먼 거리 갱신
            q.push(next);
        }
    }
    int num = 0, cnt = 1;
    for(int i=2; i<=n; ++i){
        if(visited[i] == max_d){
            if(!num) num = i; // 숨어야 하는 가장 작은 헛간 번호
            else cnt++; // 거리 같은 헛간 개수
        }
    }
    cout << num << " " << max_d-1 << " " << cnt;
}
int main(){
    cin >> n >> m;
    for(int i=0, a, b; i<m; ++i){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    solve();
    return 0;
}