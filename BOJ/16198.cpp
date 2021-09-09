// 16198번_에너지 모으기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, w, ans;
void dfs(vector<int> v, int value){
    if(v.size() == 2){ // 처음과 마지막 구슬만 남은 상태
        ans = max(ans, value);
        return;
    }
    for(int i=1; i<v.size()-1; ++i){
        vector<int> e = v; // 아무 구슬도 선택되지 않은 상태
        e.erase(e.begin()+i); // i번째 구슬 선택
        dfs(e, value+v[i-1]*v[i+1]);
    }
}
int main(){
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];
    dfs(v, 0);
    cout << ans;
    return 0;
}