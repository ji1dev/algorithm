// 1644번_소수의 연속합
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int n, ans, sum, low, high;
bool isPrime[4000001];
vector<int> prime;
int main(){
    cin >> n;
    fill_n(isPrime, n+1, true);
    for(int i=2; i*i<=n; ++i){
        if(isPrime[i]){
            for(int j=i*2; j<=n; j+=i) isPrime[j] = false;
        }
    }
    for(int i=2; i<=n; ++i){ // 입력 자연수 n까지의 소수 저장
        if(isPrime[i]) prime.push_back(i);
    }
    // high가 n까지의 소수 개수보다 커지기 전까지 반복
    // low부터 high까지 연속된 소수의 합이 n을 만족하도록 low와 high를 조절
    if(prime.size() > 0){
        while(high <= prime.size()){
            if(sum < n){
                sum += prime[high];
                high++;
            }
            else{
                sum -= prime[low];
                low++;
            }
            if(sum == n) ans++;
        }
    }
    cout << ans;
    return 0;
}