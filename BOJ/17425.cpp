// 17425번_약수의 합
#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;

// f(a) = 자연수 a의 모든 약수를 더한 값
vector<long long> f(MAX+1);

// g(x) = x보다 작거나 같은 모든 자연수의 f값을 더한 값
vector<long long> g(MAX+1);

void init(){
    // 두 자연수 a, j가 있을 때, a = i*j를 만족하는 자연수 i를 a의 약수라고 함
    // 1~MAX 까지 각 자연수의 약수를 더한 값을 각각 저장
    for(int i=1; i<=MAX; ++i){
        for(int j=1; i*j<=MAX; ++j){ // a의 약수는 a보다 클 수 없음
            f[i*j] += i;
        }
    }
    // i보다 작거나 같은 모든 자연수의 f값을 더한 값을 저장
    for(int i=1; i<=MAX; ++i){
        g[i] = g[i-1] + f[i];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t, n;
    cin >> t;
    init();
    while(t--){
        cin >> n;
        cout << g[n] << "\n";
    }
    return 0;
}