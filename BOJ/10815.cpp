// 10815번_숫자 카드
#include <iostream>
#include <algorithm>
#define MAX 500001
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, m, c[MAX], q[MAX];
int main(){
    F_IO;
    cin >> n;
    for(int i=0; i<n; ++i) cin >> c[i];
    cin >> m;
    for(int i=0; i<m; ++i) cin >> q[i];
    sort(c, c+n);
    for(int i=0; i<m; ++i){ // 찾으려는 카드 번호
        int low = 0, high = n-1;
        bool found = false;
        while(low <= high){
            int mid = (low+high)/2;
            if(c[mid] > q[i]) high = mid-1;
            else if(c[mid] < q[i]) low = mid+1;
            else{
                // 카드 찾으면 다음 카드로 넘어감
                found = true;
                break;
            }
        }
        if(found) cout << 1 << " ";
        else cout << 0 << " ";
    }
    return 0;
}