// 1068번_트리
#include <iostream>
#include <vector>
#include <queue>
#define MAX 51
using namespace std;
int n, root, del;
vector<int> g[MAX];
int solve(){
    queue<int> q;
    int visited[MAX] = {0, };
    q.push(root);
    visited[root] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int k=0; k<g[cur].size(); ++k){
            int next = g[cur][k]; // cur노드에 붙어있는 노드
            if(next==del || visited[next]) continue; // 다음 노드가 삭제 대상이면 넘어감
            visited[next] = 1;
            visited[cur]++; // cur노드에 붙어있는 노드 개수 증가
            q.push(next);
        }
    }
    int ans = 0;
    for(int i=0; i<n; ++i){ // 한번만 방문된 노드는 리프 노드임
        if(visited[i] == 1) ans++;
    }
    return ans;
}
int main(){
    cin >> n;
    for(int i=0, p; i<n; ++i){
        cin >> p;
        if(p == -1) root = i;
        else g[p].push_back(i); // p의 자식 노드 i
    }
    cin >> del; // 삭제할 노드
    cout << (root!=del ? solve() : 0); 
    return 0;
}