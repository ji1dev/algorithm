// 2109번_순회강연
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MP make_pair
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
vector<pair<int, int> > dp;
int n, ans;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        int p, d;
        cin >> p >> d;
        dp.push_back(MP(d, p));
    }
    sort(dp.begin(), dp.end()); // 날짜순 정렬
    for(int i=0; i<n; ++i){
        ans += dp[i].second;
        pq.push(dp[i].second); // 날짜순으로 강연료 push
        // i번째 날까지 pq에 들어있을 수 있는 강연 수 넘어가면 pop하고
        // top에 있는 값 빼줌
        if(dp[i].first < pq.size()){
            ans -= pq.top();
            pq.pop();   
        }
    }
    cout << ans;
    return 0;
}