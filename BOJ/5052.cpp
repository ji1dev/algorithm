// 5052번_전화번호 목록
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int t, n;
int main(){
    cin >> t;
    while(t--){
        bool flag = false;
        cin >> n;
        vector<string> v(n);
        for(int i=0; i<n; ++i) cin >> v[i];
        sort(v.begin(), v.end()); // 문자열 정렬
        for(int i=0; i<n-1; ++i){
            // i+1번째 문자열에 i번째 문자열이 접두어로 들어가지 않으면 이후 문자열에도 포함 X 
            int len1 = v[i].length();
            int len2 = v[i+1].length();
            if(len1 < len2){
                // i번째 문자열이 i+1번째 문자열의 접두어인지 확인
                if(v[i] == v[i+1].substr(0, len1)){
                    flag = true;
                    break;
                }
            }            
        }
        if(flag) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}