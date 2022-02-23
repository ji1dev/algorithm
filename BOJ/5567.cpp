// 5567번_결혼식
#include <iostream>
#include <vector>
#define MAX 501
using namespace std;
int n, m, ans;
bool map[MAX][MAX], visited[MAX];
vector<int> v;
void solve(){
    for(int i=0; i<v.size(); ++i){
        for(int j=2; j<=n; ++j){
            if(map[v[i]][j] && !visited[j]){ // 상근이의 친구의 친구
                visited[j] = true;
                ans++;
            }
        }
    }
    cout << ans;
}
int main(){
    cin >> n >> m;
    for(int i=0, a, b; i<m; ++i){
        cin >> a >> b;
        if(a == 1){ // 상근이의 친구
            v.push_back(b);
            visited[b] = true;
            ans++;
        }
        map[a][b] = map[b][a] = true;
    }
    solve();
    return 0;
}