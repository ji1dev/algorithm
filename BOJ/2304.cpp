// 2304번_창고 다각형
#include <iostream>
#include <algorithm>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, l, h[1001], area[1001], ans;
int main(){
    F_IO;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> l; // 위치
        cin >> h[l]; // 높이
    }
    int height = 0;
    // 지붕에 오목한 부분 생기면 안되므로 현 위치까지의 최대 높이로 현 위치의 다각형 면적을 계산
    for(int i=0; i<1001; ++i){
        height = max(height, h[i]);
        area[i] = height;
    }
    // 가장 높은 기둥 이후의 면적은 해당 값으로 고정되므로 반대쪽에서부터 한번 더 확인
    height = 0;
    for(int i=1000; i>=0; --i){
        height = max(height, h[i]);
        area[i] = min(area[i], height);
        ans += area[i]; // 다각형 면적 합산
    }
    cout << ans;
    return 0;
}