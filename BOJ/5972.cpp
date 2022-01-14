// 5972번_택배 배송
#include <iostream>
#include <queue>
#include <algorithm>
#define INF 987654321
#define MP make_pair
using namespace std;
int n, m, mn_dist[50001];
vector<pair<int, int> > v[50001];
void solve(){
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    mn_dist[1] = 0;
    pq.push(MP(0, 1));
    while(!pq.empty()){
        int cd = pq.top().first;
        int cv = pq.top().second;
        pq.pop();
        if(mn_dist[cv] < cd) continue;
        for(int i=0; i<v[cv].size(); ++i){
            int nd = mn_dist[cv]+v[cv][i].second;
            int nv = v[cv][i].first;
            if(mn_dist[nv] > nd){
                mn_dist[nv] = nd;
                pq.push(MP(nd, nv));
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(MP(b, c)); // 정점, 거리
        v[b].push_back(MP(a, c));
    }
    fill_n(mn_dist, 50001, INF);
    solve();
    cout << mn_dist[n];
    return 0;
}