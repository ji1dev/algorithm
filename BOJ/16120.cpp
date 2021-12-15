// 16120번_PPAP
#include <iostream>
#include <string>
using namespace std;
int cnt;
string s;
int main(){
    cin >> s;
    for(int i=0; i<s.length(); ++i){
        if(s[i] == 'P'){
            cnt++;
        }
        else{
            // A나오면 바로 뒤에 P붙으면 P -> PPAP이므로 cnt감소
            if(cnt>=2 && s[i+1]=='P'){
                cnt--;
                i++;
            }
            else{
                cout << "NP";
                return 0;
            }
        }
    }
    if(cnt == 1) cout << "PPAP";
    else cout << "NP";
    return 0;
}