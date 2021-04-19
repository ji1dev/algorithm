// 1654번_랜선 자르기
// k개 랜선을 같은 길이로 잘라서 n개 랜선 만들기
#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;
int n, k;
long long cable[MAX];

// k개 랜선을 각각 len으로 잘랐을 때 만들 수 있는 랜선 개수 확인
bool check(long long len){
    int sum = 0;
    for(int i=0; i<k; ++i) sum += cable[i]/len;
    if(sum >= n) return true;
    else return false;
}

int main(){
    // 랜선의 최소 길이는 1, 최대 길이는 k개 랜선 중 최댓값
    long long low = 1, high = 0, ans = 0;
    cin >> k >> n;
    for(int i=0; i<k; ++i){
        cin >> cable[i];
        high = max(high, cable[i]);
    }
    while(low<=high){
        long long mid = (low+high)/2;
        if(check(mid)){
            // 현재 len으로 n개 랜선을 만들 수 있으면 len을 늘림
            ans = max(ans, mid);
            low = mid+1;
        }
        else{
            // 현재 len으로 n개 랜선을 만들 수 있으면 len을 줄임
            high = mid-1;
        }
    }
    cout << ans;
    return 0;
}