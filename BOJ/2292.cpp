// 2292번_벌집
#include <iostream>
using namespace std;
int main(){
    int n, track = 0, i = 1;
    cin >> n;
    if(n == 1) cout << 1 << "\n";
    else{
        while(1){
            // track의 처음 번호와 끝 번호 사이에 들어오는지 확인
            if((6*track+2 <= n) && (n <= 6*(track+i)+1)){
                cout << i+1 << "\n";
                break;
            }
            else{
                track+=i;
                i++;
            }
        }
    }
    return 0;
}