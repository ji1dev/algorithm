// 16947번_서울 지하철 2호선
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define MP make_pair
#define MAX 3001
using namespace std;
int n, ans[MAX], prev_stn[MAX];
bool visited[MAX], cycle[MAX], isCycle;
vector<int> stn[MAX];
void dfs(int cur){
    visited[cur] = true;
    for(int i=0; i<stn[cur].size(); ++i){
        if(isCycle) return;
        int next = stn[cur][i];
        if(!visited[next]){
            prev_stn[next] = cur;
            dfs(next);
        }
        // next가 이미 방문한 역인데 cur의 부모가 next와 다르면 사이클 존재한다는 것
        else if(next != prev_stn[cur]){
            isCycle = true;
            cycle[cur] = true; // 사이클에 포함되는 역 표시
            while(cur != next){
                cycle[prev_stn[cur]] = true; // 이전 역
                cur = prev_stn[cur];
            }
            return;
        }
    }
}
void bfs(){
    queue<pair<int, int> > q;
    for(int i=1; i<=n; ++i){
        if(cycle[i]){
            visited[i] = true;
            q.push(MP(i, 0)); // 사이클에 포함된 역 까지의 거리는 0
        }
    }
    while(!q.empty()){
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();
        for(int i=0; i<stn[cur].size(); ++i){
            int next = stn[cur][i];
            if(visited[next]) continue;
            visited[next] = true;
            ans[next] = d+1; // 최초 사이클까지의 거리 0부터 시작해서 지선으로 깊게 빠질수록 1씩 늘어남
            q.push(MP(next, d+1));
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        stn[a].push_back(b);
        stn[b].push_back(a);
    }
    dfs(1);
    memset(visited, false, sizeof(visited));
    bfs();
    for(int i=1; i<=n; ++i) cout << ans[i] << " ";
    return 0;
}