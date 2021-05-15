// 1931번_회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2){
    // 종료시간이 같으면 시작시간이 빠른 순으로 정렬
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}
int main(){
    int n, a, b, end, cnt = 0;
    vector< pair<int, int> >v;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    // 종료시간 순으로 정렬, 현재 회의의 종료시간과 다음 회의의 시작시간이 같거나 그 이후인 회의를 선택
    sort(v.begin(), v.end(), cmp);
    end = v[0].second;
    cnt++;
    for(int i=1; i<n; ++i){
        if(v[i].first >= end){
            end = v[i].second;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}