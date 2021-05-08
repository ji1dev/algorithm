// 11399번_ATM
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, tmp, sum = 0;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; ++i){   
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    tmp = 0;
    for(int i=0; i<n; ++i){
        tmp += v[i];
        sum += tmp;
    }
    cout << sum;
    return 0;
}