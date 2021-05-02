// 13023번_ABCDE
#include <iostream>
#include <vector>
#define MAX 2000
using namespace std;
vector<int> friends[MAX];
bool visited[MAX];
void dfs(int v, int depth){
    visited[v] = true;
    if(depth == 4){ //depth 4까지 내려가면 관계 존재하는 것
        cout << 1;
        exit(0);
    }
    // v와 친구인 사람들을 모두 확인
    for(int u=0; u<friends[v].size(); ++u){
        // v의 친구를 아직 확인하지 않았으면
        if(!visited[friends[v][u]]) 
            // v의 친구 u의 친구 관계를 확인하는 과정 반복
            dfs(friends[v][u], depth+1);
    }
    visited[v] = false;
}
int main(){
    int n, m, v, u;
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        cin >> v >> u;
        friends[v].push_back(u); // 사람 v와 u가 관계 있음을 표시
        friends[u].push_back(v); // 사람 u와 v가 관계 있음을 표시
    }
    for(int i=0; i<n; ++i) dfs(i, 0);
    cout << 0;
    return 0;
}