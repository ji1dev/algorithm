// 1436번_영화감독 숌
#include <iostream>
using namespace std;
int main(){
    int n, tmp, scnt, cnt = 0, num = 666;
    cin >> n;
    while(1){
        scnt = 0;
        tmp = num;
        while(tmp){
            if((tmp%10) == 6) scnt++;
            else scnt = 0;            
            if(scnt == 3){
                cnt++;
                break;
            }
            tmp/=10;
        }
        if(cnt == n){
            cout << num;
            break;
        }
        num++;
    }
    return 0;
}