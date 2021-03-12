// 1912번_연속합
// n개의 정수로 이루어진 임의의 수열이 주어진다. 
// 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 
// 단, 수는 한 개 이상 선택해야 한다.
#include <iostream>
#define MAX 100000
using namespace std;
int main(){
    int n, arr[MAX+1], d[MAX+1], mx = -1001;
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> arr[i];
    }
    d[1] = arr[1];
    for(int i=2; i<=n; ++i){
        if(arr[i] >= d[i-1]+arr[i]){
            // 현재 수가 기존 연속합보다 큰 경우 현재 수를 새로운 연속합의 시작으로 설정
            d[i] = arr[i];
        }else if(arr[i] < d[i-1]+arr[i]){
            // 나머지 경우 기존 연속합을 이어나감
            d[i] = d[i-1]+arr[i];
        }
    }
    for(int i=1; i<=n; ++i){
        if(mx<d[i]) mx = d[i];
    }
    cout << mx;
    return 0;
}