// 13397번_구간 나누기 2
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, low, high, mid, ans, arr[5001];
bool check(int ub){
    int max_n, min_n, split = 1; // 1개 구간부터 시작
    max_n = min_n = arr[0];
    for(int i=1; i<n; ++i){
        min_n = min(min_n, arr[i]);
        max_n = max(max_n, arr[i]);
        // 현재 구간의 (최대원소-최소원소) 값이 상한값을 초과하면 새 구간 만들기
        if(max_n-min_n > ub){
            split++;
            min_n = arr[i];
            max_n = arr[i];
        }
    }
    return split <= m;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        high = max(high, arr[i]);
    }
    ans = 987654321;
    while(low <= high){
        mid = (low+high)/2;
        if(check(mid)){ // 구간의 점수 상한이 mid인 구간을 m개 이하로 나눌 수 있는 경우
            high = mid-1;
            ans = min(ans, mid); // 구간 점수의 최댓값의 최솟값 갱신
        }
        else{
            low = mid+1;
        }
    }
    cout << ans;
    return 0;
}