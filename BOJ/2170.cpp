// 2170번_선 긋기
#include <iostream>
#include <vector>
#include <algorithm>
#define MP make_pair
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, low, high, ans;
vector<pair<int, int> > pv;
int main(){
    F_IO;
    cin >> n;
    for(int i=0; i<n; ++i){
        int p1, p2;
        cin >> p1 >> p2;
        pv.push_back(MP(p1, p2));
    }
    sort(pv.begin(), pv.end());
    low = pv[0].first;
    high = pv[0].second;
    for(int i=1; i<n; ++i){
        if(high > pv[i].first){
            // 현재 직선의 시작점이 기존 직선 위에 있고, 끝점은 밖에 있으면 끝점 갱신
            if(high < pv[i].second){
                high = pv[i].second; 
            }   
        }
        else{
            // 나머지 경우 현재 직선이 기존 직선과 겹치지 않는 것
            // 길이 더해주고 현재 직선으로 시작, 끝점 갱신
            ans += (high-low);
            low = pv[i].first;
            high = pv[i].second;
        }
    }
    ans += (high-low); // 마지막 직선 길이
    cout << ans;
    return 0;
}