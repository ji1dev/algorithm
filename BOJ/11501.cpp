// 11501번_주식
#include <iostream>
#define MAX 1000001
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int t, n, max_cost, cost[MAX];
long long ans;
int main(){
    F_IO;
    cin >> t;
    while(t--){
        max_cost = ans = 0;
        cin >> n;
        for(int i=0; i<n; ++i) cin >> cost[i];
        for(int i=n-1; i>=0; --i){
            // 역순으로 확인하며 현재까지의 최고 가격보다 저렴하면 수익실현, 아니면 최고가 갱신
            if(max_cost > cost[i]){
                ans += max_cost-cost[i];
                continue;
            }
            max_cost = cost[i];
        }
        cout << ans << "\n";
    }
    return 0;
}