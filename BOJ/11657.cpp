// 11657번_타임머신
// Bellman-Ford 알고리즘으로 음수 간선이 포함된 그래프의 최단 거리를 구함
#include <iostream>
#include <vector>
#define MAX 501
#define INF 987654321
#define MP make_pair
using namespace std;
int n, m;
long long dist[MAX];
vector<pair<int, int> > g[MAX];
bool solve(int src){
    dist[src] = 0; // 시작 정점
    // 각 정점에서 이어지는 모든 간선을 확인하는 과정
    // 거리값이 INF가 아닌 정점으로부터 인접 정점까지의 거리가 갱신되므로 최악의 경우를 생각하여 (n-1)회 반복
    // 만약 (n-1)회차 이후에도 최단 거리값이 갱신된다면 음수 사이클이 존재한다는 의미 (-INF를 향해 거리값이 계속 감소)
    for(int i=1; i<=n; ++i){
        for(int cur=1; cur<=n; ++cur){
            for(int j=0; j<g[cur].size(); ++j){
                // 최단 거리가 INF인 정점은 현재 도달 불가능함
                // 음수 간선이 붙어있는 경우 (INF-cost) 꼴이 될 수 있으므로 걸러줌
                if(dist[cur] == INF) continue;
                int next_v = g[cur][j].first;
                int next_d = g[cur][j].second;
                // 다음 정점으로 가기 위해 현재 간선을 거치는 경우의 거리가 더 짧으면 갱신
                if(dist[next_v] > dist[cur]+next_d){
                    dist[next_v] = dist[cur]+next_d;
                    // n회차에 거리값 갱신된 경우 음수사이클 존재한다는 의미
                    // 거리값이 underflow나서 n회차까지 돌기 전에 이미 최단 거리 갱신이 더이상 발생하지 않는 경우 있음
                    // 이 경우 음수사이클이 존재함에도 판단할 수 없으므로 OLE발생하므로 거리 배열의 자료형을 long long으로 잡음
                    if(i == n) return true;
                }
            }
        }
    }
    return false;
}
int main(){
    cin >> n >> m;
    for(int i=0, a, b, c; i<m; ++i){
        cin >> a >> b >> c;
        g[a].push_back(MP(b, c)); // a->b 거리 c
    }
    for(int i=1; i<=n; ++i) dist[i] = INF; // 최단거리 테이블 초기화
    if(solve(1)) cout << -1; // 시작 정점 1, 음수 간선이 포함된 사이클 존재시 true 리턴됨
    else{
        for(int i=2; i<=n; ++i){ // 1번 정점에서 2, ..., n번 정점까지의 거리
            cout << (dist[i]!=INF ? dist[i] : -1) << "\n"; // 도달 불가능한 정점은 -1
        }
    }
    return 0;
}