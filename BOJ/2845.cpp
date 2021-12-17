// 2845번_파티가 끝나고 난 뒤
#include <iostream>
using namespace std;
int l, p, num;
int main(){
    cin >> l >> p;
    num = l*p;
    for(int i=0; i<5; ++i){
        int a;
        cin >> a;
        cout << a-num << " ";
    }
    return 0;
}