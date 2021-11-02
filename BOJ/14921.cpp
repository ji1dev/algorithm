// 14921번_용액 합성하기
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, low, high, min_rst, a[100001];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    high = n-1;
    min_rst = 987654321;
    while(low < high){
        int rst = a[low]+a[high];
        // 0에 가장 가까운 특성값의 합을 구하기 위해 더 작은 절댓값을 가지는 결과값을 구해나감
        if(abs(rst) < abs(min_rst)) min_rst = rst;
        if(rst < 0) low++; // 범위를 좁힘
        else high--;
    }
    cout << min_rst;
    return 0;
}