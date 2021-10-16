// 2217번_로프
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, w = 0;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    // 버틸 수 있는 중량이 가장 낮은 로프가 들 수 있는 물체는 나머지 로프도 들 수 있음
    // 따라서 모든 로프를 사용하는 경우 ~ 한 개의 로프만 사용하는 경우까지 순차적으로 확인
    sort(v.begin(), v.end());
    for(int i=0; i<n; ++i){
        w = max(w, v[i]*(n-i));
    }
    cout << w;
    return 0;
}