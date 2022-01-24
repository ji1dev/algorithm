// 1865번_웜홀
#include <iostream>
#include <vector>
#define MAX 501
#define INF 987654321
#define MP make_pair
using namespace std;
int tc, n, m, w;
long long dist[MAX];
vector<pair<int, int> > g[MAX];
bool solve(){
    // 벨만포드 알고리즘은 출발 정점이 정해진 상태에서 모든 간선을 확인하며 최단거리를 갱신해 나감
    // 이 때, 최단거리 갱신에 활용할 수 없는 미방문 정점을 건너뛰는 조건문을 둠
    // 이 경우 임의의 출발 정점에서 도달 불가능한 음수 사이클은 파악할 수 없음
    // 이 문제는 출발 정점이 어디든 음수 사이클이 존재하는지 여부만을 판단하면되므로 해당 조건문을 생략해도됨
    // 즉, dist[cur] == INF 은 cur을 방문했고, 그 거리가 INF라는 의미가 되므로 출발 정점이 어디라도 상관 없음
    // 그러나 실제로 도달 가능한 정점인지는 알 수 없음
    for(int i=1; i<=n; ++i){
        for(int cur=1; cur<=n; ++cur){
            for(int j=0; j<g[cur].size(); ++j){
                // if(dist[cur] == INF) continue;
                int next_v = g[cur][j].first;
                int next_d = g[cur][j].second;
                if(dist[next_v] > dist[cur]+next_d){
                    dist[next_v] = dist[cur]+next_d;
                    if(i == n) return true; // 음수 사이클 존재
                }
            }
        }
    }
    return false;
}
int main(){
    cin >> tc;
    while(tc--){
        int s, e, t;
        cin >> n >> m >> w;
        for(int i=1; i<=n; ++i){
            dist[i] = INF;
            g[i].clear();
        }
        for(int i=0; i<m; ++i){
            cin >> s >> e >> t;
            g[s].push_back(MP(e, t));
            g[e].push_back(MP(s, t));
        }
        for(int i=0; i<w; ++i){
            cin >> s >> e >> t;
            g[s].push_back(MP(e, -t));
        }
        cout << (solve() ? "YES" : "NO") << "\n";
    }
    return 0;
}