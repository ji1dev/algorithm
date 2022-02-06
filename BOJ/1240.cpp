// 1240번_노드사이의 거리
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
#define MP make_pair
using namespace std;
int n, m;
vector<pair<int, int> > v[MAX];
void solve(int a, int b){
    queue<int> q;
    int visited[MAX] = {0, };
    q.push(a);
    // visited[a] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int k=0; k<v[cur].size(); ++k){
            pair<int, int> next = v[cur][k]; // 다음 점 정보
            if(visited[next.first]) continue;
            visited[next.first] = visited[cur]+next.second;
            q.push(next.first);
        }
    }
    cout << visited[b] << "\n";
}
int main(){
    cin >> n >> m;
    for(int i=0, a, b, c; i<n-1; ++i){
        cin >> a >> b >> c;
        v[a].push_back(MP(b, c)); // 트리 상에 연결된 점 a, b와 거리 c
        v[b].push_back(MP(a, c));
    }
    for(int i=0, a, b; i<m; ++i){
        cin >> a >> b;
        solve(a, b); // a에서 b까지의 거리 구하기
    }
    return 0;
}