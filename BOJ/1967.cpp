// 1967번_트리의 지름
#include <iostream>
#include <vector>
#include <memory.h>
#define MP make_pair
using namespace std;
int n, anchor_v, longest_d;
bool visited[10001];
vector<pair<int, int> > v[10001];
void dfs(int num, int d){
    visited[num] = true;
    if(longest_d < d){
        longest_d = d;
        anchor_v = num;
    }
    for(int i=0; i<v[num].size(); ++i){
        int next = v[num][i].first;
        int dist = v[num][i].second;
        if(!visited[next]){
            dfs(next, d+dist);
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n-1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(MP(b, c)); // a, b가 cost c로 연결
        v[b].push_back(MP(a, c));
    }
    dfs(1, 0); // 정점 1과 가장 멀리 떨어진 정점을 구함
    memset(visited, false, sizeof(visited));
    longest_d = 0;
    dfs(anchor_v, 0); // 가장 멀리 떨어진 정점에서 가장 멀리 떨어진 정점을 구함
    cout << longest_d; // 그 거리가 트리의 지름이 됨
    return 0;
}