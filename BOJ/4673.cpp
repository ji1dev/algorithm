// 4673번_셀프 넘버
#include <iostream>
#define NUM 10001
using namespace std;
bool flag[NUM];
int main(){
    for(int i=1; i<NUM; ++i){
        int sum = i, tmp = i;
        // 각 자리의 숫자를 모두 더함
        while(1){
            if(tmp == 0) break;
            sum += tmp%10;
            tmp /= 10;
        }
        // 셀프 넘버가 아니면 flag표시
        if(sum <= NUM) flag[sum] = true;
    }
    for(int i=1; i<NUM; ++i){
        if(!flag[i]) cout << i << "\n";
    }
    return 0;
}