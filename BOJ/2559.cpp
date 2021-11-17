// 2559번_수열
#include <iostream>
#include <algorithm>
using namespace std;
int n, k, sum, idx, max_temp, temp[100001];
int main(){
    cin >> n >> k;
    for(int i=0; i<n; ++i) cin >> temp[i];
    max_temp = -987654321;
    for(int i=0; i<n; ++i){
        idx++;
        sum += temp[i]; // 온도 계속 더하고 k일만큼 더해진 뒤 온도 빼주기
        if(idx == k){
            max_temp = max(max_temp, sum);
            sum -= temp[i-k+1]; // 첫 날 제외해야됨
            idx--;
        }
    }
    cout << max_temp;
    return 0;
}