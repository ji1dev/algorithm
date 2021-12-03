// 10610번_30
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string s;
vector<int> v;
int sum;
int main(){
    cin >> s;
    int len = s.length();
    for(int i=0; i<len; ++i){
        int num = s[i]-'0';
        v.push_back(num); // 각 자리 수 저장
        sum += num;
    }
    sort(v.begin(), v.end());
    // 3으로 나누어 떨어지지 않거나 0으로 끝나지 않으면 30의 배수 아님
    if(sum%3!=0 || v[0]!=0){
        cout << -1;
    }
    else{
        for(int i=len-1; i>=0; --i){
            cout << v[i];
        }
    }
    return 0;
}