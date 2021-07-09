// 15663번_N과 M (9)
// N 자연수 중에서 M개를 고른 수열 (길이 M, 중복 X)
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[8], num[8];
bool visited[8];
void dfs(int len){
    if(len == m){
        for(int i=0; i<m; ++i) cout << num[i] << " ";
        cout << "\n";
        return;
    }
    int prev_num = 0;
    for(int i=0; i<n; ++i){
        // 중복 수열을 만들지 않기 위해 같은 depth에서는 같은 수를 선택하지 않도록 함
        // 입력 배열은 오름차순으로 정렬되어있으므로, 중복 값은 연속으로 저장되어 있음
        // 따라서 입력 배열에서 이전 값을 저장해두고 다음 값과 비교하면 중복을 피할 수 있음
        if(!visited[i] && prev_num!=arr[i]){
            num[len] = arr[i];
            prev_num = arr[i]; // 이전 값 저장
            visited[i] = true;
            dfs(len+1);
            visited[i] = false;
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    dfs(0);
    return 0;
}