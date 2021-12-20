// 21300번_Bottle Return
#include <iostream>
using namespace std;
int sum;
int main(){
    for(int i=0; i<6; ++i){
        int val;
        cin >> val;
        sum += val;
    }
    cout << sum*5;
    return 0;
}