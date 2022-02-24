// 17352번_여러분의 다리가 되어 드리겠습니다!
#include <iostream>
#include <vector>
#include <queue>
#define MAX 300001
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, ans;
bool visited[MAX];
vector<int> v[MAX];
void solve(){
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){ // 1번 섬에서 도달 가능한 섬 확인
        int cur = q.front();
        q.pop();
        for(int k=0; k<v[cur].size(); ++k){
            int next = v[cur][k];
            if(visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }
    for(int i=1; i<=n; ++i){
        if(!visited[i]){ // 도달 불가능한 섬 하나 찾기
            ans = i;
            break;
        }
    }
    cout << 1 << " " << ans; // 어떤 두 섬이든 연결만 하면 되므로 1번 섬과 연결시킴
}
int main(){
    F_IO
    cin >> n;
    for(int i=0, a, b; i<n-2; ++i){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    solve();
    return 0;
}