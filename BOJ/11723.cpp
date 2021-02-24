// 11723번_집합
#include <iostream>
#include <string>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    F_I;
    int m, n, set = 0;
    string cmd;
    cin >> m;
    while(m--){
        cin >> cmd;  
        if(cmd == "add"){
            cin >> n;
            set |= (1<<n);
        }
        else if(cmd == "remove"){
            cin >> n;
            set &= ~(1<<n);
        }
        else if(cmd == "toggle"){
            cin >> n;
            set ^= (1<<n);
        }
        // all 연산
        //  1 00000 00000 00000 00000 -1 = 11111 11111 11111 11111
        // 21 20 
        else if(cmd == "all"){
            set = (1<<21)-1; 
        }
        else if(cmd == "empty"){
            set = 0;
        }
        else if(cmd == "check"){
            cin >> n;
            if(set & (1<<n)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
    return 0;
}