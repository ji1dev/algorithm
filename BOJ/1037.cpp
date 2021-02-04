// 1037번_약수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> v;
    int n, divisor; 
    cin >> n; // 진짜 약수의 개수
    for(int i=0; i<n; ++i){
        cin >> divisor;
        v.push_back(divisor);
    }
    sort(v.begin(), v.end());
    // 가장 작은 진짜 약수와 가장 큰 진짜 약수를 곱함
    cout << v[0]*v[n-1] << "\n";
    return 0;
}