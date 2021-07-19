// 9613번_GCD 합
#include <iostream>
using namespace std;
int gcd(int a, int b){
    printf("%d, %d\n", a, b);
    if(b == 0) return a;
    else return gcd(b, a%b);
} 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, arr[101];
        long long sum = 0; // 범위 조심
        cin >> n;
        for(int i=0; i<n; ++i) cin >> arr[i];
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                sum += gcd(arr[i], arr[j]);
            }
        }
        cout << sum << "\n";
    }
    return 0;
}