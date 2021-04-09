// 2108번_통계학
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 500000
using namespace std;
int main(){
    int num[MAX] = {0, }, freq[8001] = {0, };
    int n, mode, tmp, mx = 0;
    double sum;
    bool isSecond = false;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> num[i];
        sum += num[i];
        tmp = num[i]<=0 ? abs(num[i]) : num[i]+4000;
        freq[tmp]++; // 각 값별 나타나는 횟수
        if(freq[tmp] > mx) mx = freq[tmp]; // 가장 많이 나타나는 값의 횟수
    }
    for(int i=-4000; i<=4000; ++i){
        tmp = i<=0 ? abs(i) : i+4000;
        if(freq[tmp] == mx){
            // 최빈값이 여러개인 경우 두 번째로 작은 값 선택
            mode = i;
            if(isSecond) break;
            isSecond = true; 
        }
    }
    sort(num, num+n);
    cout << round(sum/n) << "\n";
    cout << num[n/2] << "\n";
    cout << mode << "\n";
    cout << num[n-1]-num[0] << "\n";
    return 0;
}