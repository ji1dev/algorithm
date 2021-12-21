// 2668번_숫자고르기
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int n, a[101];
bool visited[101];
vector<int> ans;
void dfs(int r1, int r2){
    if(!visited[r2]){
        visited[r2] = true;
        dfs(r1, a[r2]);
    }
    else if(r1 == r2){
        ans.push_back(r2);
        return;
    }
}
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i){
        memset(visited, false, sizeof(visited));
        dfs(i, i);
    }
    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); ++i) cout << ans[i] << "\n";
    return 0;
}