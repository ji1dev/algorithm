// 2750번_수 정렬하기
#include <iostream>
using namespace std;
int n;
bool a[2001];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        int b;
        cin >> b;
        a[b+1000] = true;
    }
    for(int i=0; i<2001; ++i){
        if(a[i]) cout << i-1000 << "\n";
    }
    return 0;
}