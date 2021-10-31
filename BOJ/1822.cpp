// 1822번_차집합
#include <iostream>
#include <algorithm>
#define MAX 500001
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, m, cnt, a[MAX];
bool check[MAX];
int main(){
    F_IO;
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(a, a+n);
    for(int i=0; i<m; ++i){
        bool flag = false;
        int b, mid, low = 0, high = n-1;
        cin >> b;
        while(low <= high){
            mid = (low+high)/2;
            if(a[mid] > b) high = mid-1;
            else if(a[mid] < b) low = mid+1;
            else{
                check[mid] = true;
                cnt++;
                break;
            }
        }
    }
    cout << n-cnt << "\n";
    for(int i=0; i<n; ++i){
        if(!check[i]) cout << a[i] << " ";
    }
    return 0;
}