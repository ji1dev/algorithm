// 1753번_최단경로
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MP make_pair
#define INF 987654321
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int v, e, k, min_distance[20001];
vector< pair<int, int> > edge[20001];
void dijkstra(int begin){
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(MP(0, begin));
    min_distance[begin] = 0;
    while(!pq.empty()){
        int cur_d = pq.top().first; // 가장 가까이에 있는 정점과 그 거리
        int cur_v = pq.top().second;
        pq.pop();
        for(int i=0; i<edge[cur_v].size(); ++i){
            int next_d = min_distance[cur_v]+edge[cur_v][i].first; // 현재 정점을 거쳐 인접 정점까지 가는 거리
            int next_v = edge[cur_v][i].second; // 인접 정점
            if(min_distance[next_v] > next_d){ // 기존의 인접 정점까지의 최단거리와 현재 정점을 거쳐가는 거리를 비교
                min_distance[next_v] = next_d;
                pq.push(MP(next_d, next_v));
            }
        }
    }
}
int main(){
    F_IO;
    cin >> v >> e >> k; // 시작 정점 k
    for(int i=0; i<e; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back(MP(w, v)); // u에서 v로 가는 가중치 w인 간선이 존재
    }
    fill_n(min_distance, v+1, INF);
    dijkstra(k);
    for(int i=1; i<=v; ++i){
        if(min_distance[i] == INF) cout << "INF\n";
        else cout << min_distance[i] << "\n";
    }
    return 0;
}