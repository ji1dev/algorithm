// 5525번_IOIOI
#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, m, o = 0, cnt = 0;
    string str;
    cin >> n >> m >> str;
    for(int i=0; i<m; ++i){
        if(str[i] == 'O') continue; // 시작이 'O'인 경우는 skip
        while(str[i+1]=='O' && str[i+2]=='I'){ // 첫 'I'이후 "OI"가 연속되는지 확인
            o++; // 'O'개수 ++
            i += 2; // 다음 확인할 Pn패턴의 첫 index는 현재 index+2
            if(o == n){
                cnt++; // n(='O'개수) 와 현재까지 확인한 "OI"단위에서 나온 'O'의 개수가 같으면 Pn 개수++
                o--; // 'O'개수 중복 count막기 위해 --
            }
        }
        o = 0; // 새로운 Pn 시작 전에 'O'개수 count 초기화
    }
    cout << cnt;
    return 0;
}