// 1477번_휴게소 세우기
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, l, low, high, mid, ans, r_area[1001];
bool check(int len){
    int sum = 0;
    if(len == 0) return false; // 간격이 0인 경우 설치할 수 없음
    for(int i=1; i<=n+1; ++i){
        int diff = r_area[i]-r_area[i-1]; // 두 휴게소 사이 거리
        int cnt = (diff-1)/len; // 현재 길이 간격으로 설치할 수 있는 휴게소 개수 (설치된 위치 제외)
        if(cnt > 0) sum += cnt;
    }
    return sum <= m;
}
int main(){
    cin >> n >> m >> l;
    for(int i=1; i<=n; ++i) cin >> r_area[i];
    r_area[n+1] = l;
    sort(r_area, r_area+n+2); // 첫 휴게소까지의 구간, 마지막 휴게소에서 도로 끝 까지의 구간 유의
    high = l;
    while(low <= high){
        mid = (low+high)/2;
        if(check(mid)){ // m개 이하로 지을 수 있으므로 상한을 내림 (간격 줄어듦)
            ans = mid;
            high = mid-1;
        }
        else{ // m개 초과해서 지을 수 있으므로 하한을 올림 (간격 늘어남)
            low = mid+1;
        }
    }
    cout << ans;
    return 0;
}