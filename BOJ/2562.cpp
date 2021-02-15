// 2562번_최댓값
#include <iostream>
using namespace std;
int main(){
    int input, max = 0, idx = 0;
    for(int i=0; i<9; ++i){
        cin >> input;
        if(max < input){
            max = input;
            idx = i;
        }
    }
    cout << max << "\n" << idx+1 << "\n";
    return 0;
}