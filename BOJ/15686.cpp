// 15686번_치킨 배달
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 987654321
#define MP make_pair
using namespace std;
int n, m, ans, map[51][51], dist[101]; // 집 개수는 최대 2n개
vector< pair<int, int> > h, c, sc; // 집, 치킨집, 선택된 치킨집
void init(){
    for(int i=0; i<101; ++i) dist[i] = INF;
}
void dfs(int selected, int idx){
    if(selected == m){
        int sum = 0;
        for(int p=0; p<h.size(); ++p){
            int hi = h[p].first;
            int hj = h[p].second;
            for(int q=0; q<m; ++q){
                int ci = sc[q].first;
                int cj = sc[q].second;
                dist[p] = min(dist[p], abs(hi-ci)+abs(hj-cj)); // 각 집에서 치킨집까지 최소 거리 계산
            }
            sum += dist[p];   
        }
        ans = min(ans, sum);
        init(); // 치킨 거리 초기화
        return;
    }
    for(int i=idx; i<c.size(); ++i){
        sc.push_back(c[i]); // i번째 치킨집 선택
        dfs(selected+1, i+1); // 다음 치킨집부터 확인
        sc.pop_back();
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> map[i][j];
            if(map[i][j] == 1) h.push_back(MP(i, j));
            if(map[i][j] == 2) c.push_back(MP(i, j));
        }
    }
    ans = INF;
    init();
    dfs(0, 0); // 선택한 치킨집 수, 치킨집 번호
    cout << ans;
    return 0;
}