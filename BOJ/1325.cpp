// 1325번_효율적인 해킹
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MP make_pair
#define MAX 10001
using namespace std;
int n, m, max_cnt;
vector<int> v[MAX];
vector<pair<int, int> > res; // 각 컴퓨터별 해킹 가능한 대수 저장
void solve(){
    for(int i=1; i<=n; ++i){
        queue<int> q;
        bool visited[MAX] = {0, };
        int cnt = 0;
        q.push(i);
        visited[i] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int k=0; k<v[cur].size(); ++k){
                int next = v[cur][k];
                if(visited[next]) continue;
                visited[next] = true;
                q.push(next);
                cnt++; // 연쇄적으로 해킹되는 컴퓨터 대수
            }
        }
        res.push_back(MP(i, cnt)); 
        max_cnt = max(max_cnt, cnt); // 연쇄 해킹 가능한 컴퓨터 대수 최댓값 갱신
    }
    sort(res.begin(), res.end()); // 컴퓨터 번호순 오름차순 정렬
    for(int i=0; i<res.size(); ++i){
        if(res[i].second == max_cnt) cout << res[i].first << " ";
    }
}
int main(){
    cin >> n >> m;
    for(int i=0, a, b; i<m; ++i){
        cin >> a >> b;
        v[b].push_back(a); // a가 b를 신뢰 (= b 해킹시 a 해킹가능)
    }
    solve();
    return 0;
}