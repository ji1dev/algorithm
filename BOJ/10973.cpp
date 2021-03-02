// 10973번_이전 순열
#include <iostream>
#include <algorithm>
using namespace std;
int n, idx = -1, arr[10000];
bool desc(int a, int b){
    return a>b;
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    // 입력 순열을 뒤에서부터 확인하며 i-1번째 수 > i번째 수가 나오는 지점을 찾음
    // 위 경우가 없다면 첫 순열이므로 -1 출력 후 종료
    // 순열의 뒷부분부터 살피며 위에서 찾은 지점 바로 앞의 수 보다 작은 수를 찾아 교환
    // 지점의 뒷부분을 내림차순으로 정렬
    for(int i=n-1; i>0; --i){
        if(arr[i-1] > arr[i]){ 
            idx = i-1;
            break;
        }
    }
    if(idx == -1){
        cout << -1;
        return 0;
    }
    for(int i=n-1; i>idx; --i){
        if(arr[idx] > arr[i]){
            swap(arr[idx], arr[i]);
            break;
        }
    }
    sort(arr+idx+1, arr+n, desc);
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
    return 0;
}