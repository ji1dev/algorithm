// 1916번_최소비용 구하기
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MP make_pair
using namespace std;
vector< pair<int, int> > v[100001];
int min_d[1001];
void minDistance(int begin){
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    min_d[begin] = 0; // begin으로 가는 최단 거리는 0
    pq.push(MP(0, begin));
    while(!pq.empty()){
        // 최단 거리에 있는 정점과 그 거리
        int cur_v = pq.top().second;
        int cur_d = pq.top().first; 
        pq.pop();
        if(min_d[cur_v] < cur_d) continue; // 계산된 최단 거리를 갱신할 필요 없는 경우 넘어감
        for(int i=0; i<v[cur_v].size(); ++i){
            int next_v = v[cur_v][i].first; // 인접 정점과 현재 정점을 거쳐 인접 정점까지 가는 거리
            int next_d = min_d[cur_v]+v[cur_v][i].second; 
            if(min_d[next_v] > next_d){ // 인접 정점까지의 기존 최단 거리와 현재 정점 거쳐가는 거리를 비교 및 갱신
                min_d[next_v] = next_d;
                pq.push(MP(next_d, next_v));
            }
        }
    }
}
int main(){
    int n, m, begin, end;
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c; // 출발 정점, 도착 정점, 거리
        v[a].push_back(MP(b, c));
    }
    cin >> begin >> end;
    fill_n(min_d, 1001, 987654321);
    minDistance(begin); // begin에서 다른 모든 정점으로 가는 최단 거리를 구함
    cout << min_d[end]; // end까지 가는 최단 거리
    return 0;
}