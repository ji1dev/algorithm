// 7568번_덩치
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, rank[50] = {0, };
    cin >> n;
    vector< pair<int, int> >v(n);
    for(int i=0; i<n; ++i){
        // 키, 몸무게 쌍을 입력받음
        cin >> v[i].first >> v[i].second;
    }
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            // i번째 사람보다 j번째 사람의 키, 몸무게가 모두 크면 i번째 사람의 덩치 순위가 밀림
            // 반대의 경우 j번째 사람의 덩치 순위가 밀림
            if((v[i].first < v[j].first) && (v[i].second < v[j].second)) rank[i]++;
            if((v[i].first > v[j].first) && (v[i].second > v[j].second)) rank[j]++;
        }
    }
    for(int i=0; i<n; ++i) cout << rank[i]+1 << " ";
    return 0;
}