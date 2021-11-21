// 1339번_단어 수학
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, ans, a[27];
string s;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> s;
        int cnt = 1;
        // 입력 문자열에 포함된 각 문자의 자릿수에 따라 개수를 구함
        // e.g. AAA = A 1개 + A 10개 + A 100개 = 111개
        for(int k=(s.length()-1); k>=0; --k){
            a[s[k]-'A'] += cnt;
            cnt *= 10;
        }
    }
    sort(a, a+27); // 각 문자의 개수에 따라 정렬
    int num = 9;
    for(int k=26; k>=0; --k){
        ans += a[k]*num; // 개수 많은 문자부터 9, 8, ... 곱함
        num--;
    }
    cout << ans;
    return 0;
}