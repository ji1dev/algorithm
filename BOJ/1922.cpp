// 1922번_네트워크 연결
#include <iostream>
#include <queue>
#include <vector>
#define MP make_pair
using namespace std;
int n, m, a, b, c, ans;
bool visited[1001];
vector< pair<int, int> > com[1001];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
void prim(){
    pq.push(MP(0, 1)); // 1번 컴퓨터부터 시작, cost기준 오름차순 정렬됨
    while(!pq.empty()){
        int cost = pq.top().first;
        int num = pq.top().second;
        pq.pop();
        if(!visited[num]){
            visited[num] = true;
            ans += cost;
            for(int i=0; i<com[num].size(); ++i){
                // 현재 컴퓨터와 연결 가능한 다른 컴퓨터들 중 아직 확인하지 않은 컴퓨터를 우선순위 큐에 넣음
                if(!visited[com[num][i].second]) pq.push(com[num][i]);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        cin >> a >> b >> c;
        com[a].push_back(MP(c, b)); // com[a] = a컴퓨터와 b컴퓨터를 연결하는 비용 c
        com[b].push_back(MP(c, a));
    }
    prim();
    cout << ans;
    return 0;
}