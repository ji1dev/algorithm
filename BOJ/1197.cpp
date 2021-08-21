// 1197번_최소 스패닝 트리
#include <iostream>
#include <vector>
#include <queue>
#define MP make_pair
using namespace std;
vector< pair<int, int> > vt[10001];
bool visited[10001];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
long long prim(){
    long long ans = 0;
    pq.push(MP(0, 1)); // 1번 정점에서 시작 (가중치 0)
    while(!pq.empty()){
        int w = pq.top().first; // 가중치
        int v = pq.top().second; // 정점 번호
        pq.pop();
        if(!visited[v]){
            visited[v] = true;
            ans += w;
            for(int i=0; i<vt[v].size(); ++i){
                // 정점 v와 연결된 정점들 중 아직 방문하지 않은 정점까지의 간선 가중치와 번호를 큐에 push
                if(!visited[vt[v][i].first]){
                    pq.push(MP(vt[v][i].second, vt[v][i].first));
                }
            }
        }
    }
    return ans;
}
int main(){
    int v, e, a, b, c;
    cin >> v >> e;
    for(int i=0; i<e; ++i){
        cin >> a >> b >> c;
        vt[a].push_back(MP(b, c)); // vt[a] = 정점a와 b가 가중치 c인 간선으로 이어짐
        vt[b].push_back(MP(a, c));
    }
    cout << prim(); // 현재 신장 트리에서 가장 낮은 가중치로 도달할 수 있는 정점들을 추가해나감
    return 0;
}