// 2485번_가로수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> tree;
int n, space, ans;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        int loc;
        cin >> loc;
        tree.push_back(loc);
        // 가로수 간격의 최대 공약수
        if(i > 0) space = gcd(space, tree[i]-tree[i-1]);
    }
    // 전체 가로수 개수는 첫 가로수와 마지막 가로수의 거리 차이를 최대공약수로 나눈것
    ans = (tree[n-1]-tree[0])/space-n+1; // 새로 심어야 되는 가로수 개수ㄴ
    cout << ans;
    return 0;
}