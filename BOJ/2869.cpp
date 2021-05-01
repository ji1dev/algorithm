// 2869번_달팽이는 올라가고 싶다
#include <iostream>
using namespace std;
int main(){
    int a, b, v, day, tmp;
    cin >> a >> b >> v;
    // 첫날은 올라가기만 하므로 (v-a)해준 뒤 남은 높이만큼 (a-b)로 나눠 며칠이 걸리는지 구함
    day = (v-a)/(a-b)+1;
    if(!((v-a)%(a-b))) cout << day;
    else cout << day+1;
    return 0;
}