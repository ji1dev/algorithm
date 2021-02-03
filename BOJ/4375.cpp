// 4375번_1
#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        int cnt=1;
        int m=1;
        while(1){
            if(m%n == 0) break;
            m = (m*10+1)%n;
            cnt++;  
        }
        cout << cnt << "\n";
    }
    return 0;
}