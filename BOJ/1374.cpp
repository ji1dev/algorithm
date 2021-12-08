// 1374번_강의실
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MP make_pair
using namespace std;
int n, cnt;
vector<pair<int, int > > v;
priority_queue<int, vector<int>, greater<int> > pq;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(MP(b, c));
    }
    sort(v.begin(), v.end());
    pq.push(v[0].second);
    for(int i=1; i<n; ++i){
        if(pq.top() > v[i].first) cnt++;
        else pq.pop(); 
        pq.push(v[i].second); // 확인한 강의의 종료시간
    }
    cout << cnt+1;
    return 0;
}