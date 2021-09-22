// 14225번_부분수열의 합
#include <iostream>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, arr[21];
bool value[2000001]; // 범위 신경쓰기
void dfs(int idx, int sum){
    if(idx == n){
        value[sum] = true;
        return;
    }
    dfs(idx+1, sum+arr[idx]); // 현재 숫자 포함
    dfs(idx+1, sum); // 숫자 미포함
}
int main(){
    F_IO;
    int min_v = 1;
    cin >> n;
    for(int i=0; i<n; ++i) cin >> arr[i];
    dfs(0, 0);
    while(value[min_v] == true) min_v++; // 끊기는 곳의 수가 만들 수 없는 가장 작은 자연수
    cout << min_v;
    return 0;
}