// 16968번_차량 번호판 1
#include <iostream>
#include <string>
#define COND str[i]=='c'
using namespace std;
string str;
void solve(){
    int ans = 1;
    for(int i=0; i<str.length(); ++i){
        if(i == 0) ans *= (COND ? 26 : 10); // characters, digits
        else{
            if(str[i] == str[i-1]){
                ans *= (COND ? 25 : 9); // 같은 종류 연속 두번 허용 x
            }
            else{
                ans *= (COND ? 26 : 10);
            }
        }
    }
    cout << ans;
}
int main(){
    cin >> str;
    solve();
    return 0;
}