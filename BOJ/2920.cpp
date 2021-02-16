// 2920번_음계
#include <iostream>
using namespace std;
int main(){
    int n, a = 0, b = 0;
    int scale[] = {1, 2, 3, 4, 5, 6, 7, 8};
    for(int i=0; i<8; ++i){
        cin >> n;
        if(scale[i] == n){
            a++;
        }else if(scale[7-i] == n){
            b++;
        }
    }
    if(a == 8) cout << "ascending\n";
    else if(b == 8) cout << "descending\n";
    else cout << "mixed\n";    
    return 0;
}