// 10819번_차이를 최대로
// |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| 의 최댓값
#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[8], ans[8], mx = 0;
bool isUsed[8];
void solve(int idx){
    if(idx == n){
        int tmp = 0;
        for(int i=0; i<n-1; ++i){
            tmp += abs(ans[i]-ans[i+1]);
        }
        mx = max(mx, tmp);
        return;
    }
    for(int i=0; i<n; ++i){
        if(!isUsed[i]){
            isUsed[i] = true;
            ans[idx] = arr[i];
            solve(idx+1);
            isUsed[i] = false;
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    solve(0);
    cout << mx << "\n";
    return 0;
}