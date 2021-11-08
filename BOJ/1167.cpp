// 1167번_트리의 지름
#include <iostream>
#include <vector>
#include <memory.h>
#define MP make_pair
using namespace std;
int n, max_d, max_v;
bool visited[100001];
vector<pair<int, int> > v[100001];
void dfs(int vno, int d){
    visited[vno] = true;
    if(max_d < d){
        max_d = d;
        max_v = vno;
    }
    for(int i=0; i<v[vno].size(); ++i){
        int next = v[vno][i].first;
        if(!visited[next]){
            dfs(next, v[vno][i].second+d);
        }
    }
}
int main(){
    // 임의의 정점에서 가장 먼 정점x를 찾고, x에서 가장 먼 정점y를 찾아 그 거리를 구함
    cin >> n;
    for(int i=0; i<n; ++i){
        int a, b, c;
        cin >> a;
        while(1){
            cin >> b;
            if(b == -1) break;
            cin >> c;
            v[a].push_back(MP(b, c));
            v[b].push_back(MP(a, c));
        }
    }
    dfs(1, 0); // 1번 정점 기준으로 가장 멀리 있는 정점 찾기
    max_d = 0;
    memset(visited, false, sizeof(visited));
    dfs(max_v, 0); // 1번 정점에서 가장 멀리 있는 정점 기준 가장 멀리 있는 정점 찾기
    cout << max_d; // 트리의 지름
    return 0;
}