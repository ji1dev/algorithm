// 1550번_16진수
#include <iostream>
#include <string>
using namespace std; 
int ans;
string s;
int main(){
    cin >> s;
    for(int i=0; i<s.length(); ++i){
        ans *= 16;
        // A~F는 10더해주기
        if(s[i]>='A' && s[i]<='F') ans += s[i]-'A'+10;
        else ans += s[i]-'0';
    }
    cout << ans;
    return 0;
}