// 2460번_지능형 기차
#include <iostream>
#include <algorithm>
using namespace std;
int max_p, p, a, b;
int main(){
    for(int i=0; i<10; ++i){
        cin >> a >> b;
        p += b-a; // 내리고 타는 인원 차이
        max_p = max(max_p, p);
    }
    cout << max_p;
    return 0;
}