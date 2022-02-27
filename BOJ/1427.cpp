// 1427번_소트인사이드
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 11
using namespace std;
char n[MAX];
int len;
int main(){
    cin >> n;
    len = strlen(n);
    sort(n, n+len, greater<int>());
    for(int i=0; i<len; ++i){
        cout << n[i];
    }
    return 0;
}