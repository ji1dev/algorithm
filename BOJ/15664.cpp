// 15664번_N과 M (10)
// N 자연수 중에서 M개를 고른 수열 (중복X, 길이 M, 오름차순 수열만)
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[8], num[8];
bool visited[8];
void seq(int len){
    if(len == m){
        for(int i=0; i<m; ++i) cout << num[i] << " ";
        cout << "\n";
        return;
    }
    int prev = -1;
    for(int i=0; i<n; ++i){
        // 중복 수열을 피하기 위해 같은 depth에서는 같은 수가 추가되지 않도록 함
        // 이를 위해 현재 확인중인 수와, 직전에 추가된 수를 비교함
        // 수열이 오름차순으로 생성되도록 이전 자리보다 크거나 같은 수만 추가함
        if(!visited[i] && prev!=arr[i] && arr[i]>=num[len-1]){
            num[len] = arr[i];
            prev = arr[i]; // 현재 depth에서 수열에 추가한 수를 저장
            visited[i] = true;
            seq(len+1);
            visited[i] = false;
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    seq(0);
    return 0;
}