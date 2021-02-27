// 1920번_수 찾기
#include <iostream>
#include <algorithm>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, m, arr[100000], input;
int Find(int left, int right, int num){
    if(left <= right){
        int mid = (left+right)/2;
        if(num == arr[mid]) return 1;
        else if(num < arr[mid]) return Find(left, mid-1, num);
        else if(num > arr[mid]) return Find(mid+1, right, num);
    }
    return 0;
}

int main(){
    F_I;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    // 입력 배열을 오름차순으로 정렬 후 이진탐색
    sort(arr, arr+n);
    cin >> m;
    for(int i=0; i<m; ++i){
        cin >> input;
        cout << Find(0, n-1, input) << "\n";
    }
    return 0;
}