// 11054번_가장 긴 바이토닉 부분 수열
#include <iostream>
#include <algorithm>
using namespace std;
int n, smax, lbsLen;
int s[1001], dpl[1001], dpr[1001];
// 수열의 앞에서부터 LIS 길이를 구하는 함수
void LeftLIS(){
    dpl[1] = 1;
    for(int k=1; k<=n; ++k){
        int nearest = 0;
        for(int i=0; i<k; ++i){
            if(s[i] < s[k]) nearest = max(nearest, dpl[i]);
            dpl[k] = nearest+1;
        }
    }
}
// 수열의 뒤에서부터 LIS 길이를 구하는 함수
void RightLIS(){
    dpr[n] = 1;
    for(int k=n-1; k>=1; --k){
        int nearest = 0;
        for(int i=n; i>k; --i){
            if(s[i] < s[k]) nearest = max(nearest, dpr[i]);
            dpr[k] = nearest+1;
        }
    }
}
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> s[i];
    LeftLIS();
    RightLIS();
    // 수열의 앞, 뒤에서 부터 각각 구한 i번째 원소에서의 LIS 길이값을 더해보며 LBS 길이를 구함
    // i번째 수가 각 LIS에서 중복되므로 -1 해줌
    for(int i=1; i<=n; ++i){
        lbsLen = max(lbsLen, dpl[i]+dpr[i]-1);
    }
    cout << lbsLen;
    return 0;
}