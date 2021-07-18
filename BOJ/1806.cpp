// 1806번_부분합
#include <iostream>
#include <algorithm>
#define MAX_N 100001
#define MAX_L 987654321
using namespace std;
int arr[MAX_N];
int main(){
    int n, s, len;
    int begin = 0, end = 0, sum = 0, min_len = MAX_L;
    cin >> n >> s;
    for(int i=0; i<n; ++i) cin >> arr[i];
    // 입력 수열의 마지막 원소를 넘기기 전까지 begin, end index를 옮기며 부분합을 구함
    while(end <= n){
        if(sum < s) sum += arr[end++]; // 현재 end index의 원소를 더하고 end 증가
        else if(sum >= s){
            // 부분합이 목표합과 같거나 더 큰 경우
            len = end-begin;
            min_len = min(min_len, len);
            sum -= arr[begin++]; // 현재 begin index의 원소를 빼고 begin 증가
        }
    }
    if(min_len == MAX_L) cout << 0;
    else cout << min_len;
    return 0;
}