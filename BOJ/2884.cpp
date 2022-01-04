// 2884번_알람 시계
#include <iostream>
using namespace std;
int main(){
    int h, m, tmp;
    cin >> h >> m;
    tmp = h * 60 + m - 45;
    if(tmp < 0) tmp += 60*24;
    h = tmp/60;
    m = tmp%60;
    cout << h << " " << m << "\n";
    return 0;
}