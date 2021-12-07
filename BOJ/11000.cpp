// 11000번_강의실 배정
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MP make_pair
using namespace std;
int n;
vector<pair<int, int> > v;
priority_queue<int, vector<int>, greater<int> > pq;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        int s, t;
        cin >> s >> t;
        v.push_back(MP(s, t));
    }
    sort(v.begin(), v.end());
    pq.push(v[0].second); // 첫 강의의 종료시간
    for(int i=1; i<n; ++i){
        // 수업 끝난 직후 다음 수업 시작 가능 (강의실 이어서 사용 가능한 경우) 
        if(pq.top() <= v[i].first) pq.pop();
        pq.push(v[i].second); // 확인한 강의의 종료시간
    }

    cout << pq.size(); // 남은 원소 수는 필요한 강의실 개수와 같음
    return 0;
}