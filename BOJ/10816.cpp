// 10816번_숫자 카드 2
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr1[500000], arr2[500000];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> arr1[i];
    cin >> m;
    for(int i=0; i<m; ++i) cin >> arr2[i];

    // upper_bound, lower_bound는 이진탐색 기반이므로 먼저 배열을 정렬함
    sort(arr1, arr1+n);

    for(int i=0; i<m; ++i){
        // lower_bound = 범위 내에서 value값의 하한
        // value와 같거나 큰 값이 처음 나타나는 위치
        int lower = lower_bound(arr1, arr1+n, arr2[i]) - arr1;

        // upper_bound = 범위 내에서 value값의 상한
        // value보다 큰 값이 처음 나타나는 위치
        int upper = upper_bound(arr1, arr1+n, arr2[i]) - arr1;

        // upper-lower=0 이면 해당 value가 배열에 없는 것
        // 그 외 경우는 value가 몇 개 포함되어 있는지 알 수 있음
        cout << upper-lower << " ";
    }
    return 0;
}