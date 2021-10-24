// 15903번_카드 합체 놀이
#include <iostream>
#include <algorithm>
using namespace std;
long long ans, card[1000001];
int n, m;
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> card[i];
    // 오름차순 정렬하고 가장 작은 수, 그 다음으로 작은 수를 더한 뒤 값 갱신
    // 갱신 결과에 대해 다시 오름차순 정렬하고 같은 과정 반복
    for(int i=0; i<m; ++i){
        sort(card, card+n);
        long long sum = card[0]+card[1];
        card[0] = sum;
        card[1] = sum;
    }
    for(int i=0; i<n; ++i) ans += card[i];
    cout << ans;
    return 0;
}