// 2577번_숫자의 개수
#include <iostream>
#include <string>
using namespace std;
int main(){
    int a, b, c, rst, len, ans[10]={0,};
    string str;
    cin >> a >> b >> c;
    str = to_string(a * b * c);
    len = str.length();
    for(int i=0; i<len; ++i){
        ans[str[i]-'0']++;
    }
    for(int i=0; i<10; ++i){
        cout << ans[i] << "\n";
    }
    return 0;
}