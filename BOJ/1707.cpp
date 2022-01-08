// 1707번_이분 그래프
// 모든 정점이 두 그룹으로 나눠지고, 서로 다른 그룹의 정점이 간선으로 연결됨
// 즉, 같은 그룹에 속한 정점끼리는 서로 인접하지 않음
// 사이클 존재한다고 반드시 이분 그래프 충족하지 않는 것은 아님
#include <iostream>
#include <vector>
#include <memory.h>
#define MAX 20001
using namespace std;
int k, v, e;
int visited[MAX];
vector<int> g[MAX];
bool solve(int src, int color){
    visited[src] = color;
    for(int u=0; u<g[src].size(); ++u){
        int next = g[src][u];
        if(!visited[next]){
            // 아직 방문하지 않은 다음 정점을 다른 그룹에 넣고, 탈출 시점에 이분 그래프를 충족하면 인접 정점을 계속 확인
            // return solve(next, -color); // 계속 WA터진 부분, 이러면 충족 여부와 관계없이 무조건 return하게됨
            if(!solve(next, -color)) return false;
        }
        else if(visited[src] == visited[next]){
            return false; // 인접 정점이 같은 그룹인 경우
        }
    }
    return true;
}
int main(){
    cin >> k;
    while(k--){
        bool flag = true;
        cin >> v >> e;
        for(int i=0; i<e; ++i){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int u=1; u<=v; ++u){ // 비연결 그래프가 존재할 수 있으므로 시작 정점 모두 확인
            if(!visited[u]){
                if(!solve(u, 1)){
                    flag = false;
                    cout << "NO\n";
                    break;
                }
            }
        }
        if(flag) cout << "YES\n";
        memset(visited, 0, sizeof(visited));
        for(int i=1; i<=v; ++i) g[i].clear();
    }
    return 0;
}