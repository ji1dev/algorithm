// 2309번_일곱 난쟁이
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> height;
    int n, sum = 0;
    bool flag = false;
    
    for(int i=0; i<9; ++i){
        cin >> n;
        sum += n;
        height.push_back(n);
    }

    sort(height.begin(), height.end());

    for(int i=0; i<8; ++i){
        for(int j=1; j<9; ++j){
            // 난쟁이 키의 총합에서 두 난쟁이의 키를 빼서 100이 되면
            // 해당 난쟁이들을 제외시킴
            if(sum - (height[i]+height[j]) == 100){
                height[i] = 0;
                height[j] = 0;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    for(int i=0; i<9; i++){
        if(height[i]) cout << height[i] << "\n";
    }
    return 0;
}