// 16401번_과자 나눠주기
#include <iostream>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int m, n, c[1000001];
int low, high, mid, cnt, ans;
int main(){
    F_IO;
    cin >> m >> n;
    for(int i=0; i<n; ++i){
        cin >> c[i];
        high = max(high, c[i]);
    }
    low = 1; // 과자 길이가 존재해야됨
    while(low <= high){
        cnt = 0;
        mid = (low+high)/2;
        for(int i=0; i<n; ++i){ // 현재 mid길이로 나눠지는 과자 조각 개수
            cnt += c[i]/mid;
        }
        if(cnt >= m){ // 조카의 수 보다 과자 조각이 많은 경우
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout << ans;
    return 0;
}