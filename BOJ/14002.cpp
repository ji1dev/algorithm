// 14002번_가장 긴 증가하는 부분 수열 4
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, a[1001], d[1001], mx = 1;
    vector<int> ans;
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    d[1] = 1;
    for(int i=2; i<=n; ++i){
        int currentMax = 0;
        // i번째 원소까지의 가장 긴 증가하는 부분 순열의 길이는
        // 자기 자신보다 작은 원소들 중 가장 큰 값 까지의 가장 긴 증가하는 부분 순열 길이+1
        for(int j=1; j<i; ++j){
            if(a[i] > a[j]){
                currentMax = max(currentMax, d[j]);
            }
            d[i] = currentMax+1;
            mx = max(mx, d[i]);
        }
    }
    cout << mx << "\n";
    // 인덱스에 해당하는 원소까지의 lis 길이를 저장한 배열 d를 뒤에서 부터 확인하며 
    // lis의 마지막 수 부터 거꾸로 차례대로 저장
    for(int y=n; y>=1; --y){
        if(d[y] == mx){
            ans.push_back(a[y]);
            mx--;
        }
    }
    for(int i=ans.size()-1; i>=0; --i){
        cout << ans[i] << " ";
    }
    return 0;
}