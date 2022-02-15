// 12904번_A와 B
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s, t;
int main(){
    cin >> s >> t;
    while(s.length() != t.length()){
        // 문자열 끝이 A이면 1번 연산의 결과이므로 A제거
        if(t[t.length()-1] == 'A'){
            t.pop_back();
        }
        // 문자열 끝이 B이면 2번 연산의 결과이므로 B제거 후 뒤집음
        else{
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    // 변환 결과인 t에서 s로 거슬러 올라가며 확인한 결과
    cout << (s==t ? 1 : 0);
    return 0;
}