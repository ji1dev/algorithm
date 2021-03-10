// 11053번_가장 긴 증가하는 부분 수열
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, arr[1001], d[1001], mx = 1;
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> arr[i];
    d[1] = 1;
    for(int i=2; i<=n; ++i){
        int cmax = 0;
        // i번째 원소까지의 가장 긴 증가하는 부분 순열의 길이는
        // 자기 자신보다 작은 원소들 중 가장 큰 값 까지의 가장 긴 증가하는 부분 순열 길이+1
        for(int j=1; j<i; ++j){
            if(arr[i] > arr[j]){
                cmax = max(cmax, d[j]); 
            }  
        }
        d[i] = cmax+1;
        mx = max(mx, d[i]);
    }
    cout << mx;
    return 0;
}