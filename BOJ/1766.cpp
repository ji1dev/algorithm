// 1766번_문제집
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m, indeg[32001];
vector<int> v[32001];
priority_queue<int, vector<int>, greater<int> > pq;
int main(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        indeg[b]++; // indegree 개수를 저장
    }
    for(int i=1; i<=n; ++i){
        if(indeg[i] == 0) pq.push(i); // indegree 0개인 정점 push
    }
    while(!pq.empty()){ // 모든 문제 풀어야 함
        int cur = pq.top();
        pq.pop();
        cout << cur << " "; // 가능하면 쉬운 문제부터, 먼저 푸는 것이 좋은 문제부터 품
        // 현재 정점에서 나가는 outdegree 지워서 연결된 정점의 indegree 0되면 push
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i]; 
            indeg[next]--;
            if(indeg[next] == 0) pq.push(next);
        }
    }
    return 0;
}