// 13144번_List of Unique Numbers
#include <iostream>
using namespace std;
int n, low, high, seq[100001];
bool visited[100001];
long long ans;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> seq[i];
    while(low < n){
        while(high < n){
            // 같은 수 나올때까지 high 이동하면서 방문처리
            if(visited[seq[high]]) break;
            visited[seq[high]] = true;
            high++;
        }
        ans += (high-low); // 중복 없는 수열의 개수
        visited[seq[low]] = false; // 시작점 원소 방문처리 해제
        low++; // 시작점 이동
    }
    cout << ans;
    return 0;
}