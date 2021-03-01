// 2798번_블랙잭
#include <iostream>
#include <cmath>
using namespace std;
int n, m, card[100], diff, ans;
bool isUsed[100], flag = false;
void solve(int cnt, int sum){
    if(sum > m) return;
    if(cnt == 3){
        if(abs(sum-m) < diff){
            diff = abs(sum-m);
            ans = sum;
            if(sum == m) flag = true;
        }
        return;
    }
    for(int i=0; i<n; ++i){
        if(!flag && !isUsed[i]){
            isUsed[i] = true;
            solve(cnt+1, sum+card[i]);
            isUsed[i] = false;
        }
    }
}
int main(){
    cin >> n >> m;
    diff = m;
    for(int i=0; i<n; ++i){
        cin >> card[i];
    }
    solve(0, 0);
    cout << ans;
    return 0;
}