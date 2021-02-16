// 6064번_카잉 달력
#include <iostream>
using namespace std;
int t, m, n, x, y;

int GCD(int a, int b){
    if(b == 0) return a;
    else return GCD(b, a%b);
}

int Getyear(){
    int tmp_y, max, year = -1;
    max = (m*n)/GCD(m, n); // 카잉 달력의 마지막 해는 LCM(M,N)
    
    // x에 부합하는 year을 찾고
    // 해당 year에 부합하는 y를 구해서 입력된 y와 비교함
    for(int i=0; x+i*m<=max; ++i){
        tmp_y = (x+i*m)%n;
        // 현재 year에 부합하는 y와 입력된 y가 같은 경우 올바른 year를 찾은 것
        // y와 n이 같을 때 tmp_y가 0이 될 수 있으므로 조건 추가
        if(tmp_y == y || (tmp_y == 0 && y == n)){
            year = x+i*m;
            break;
        }
    }
    return year;
}

int main(){
    cin >> t;
    while(t--){
        cin >> m >> n >> x >> y;
        cout << Getyear() << "\n";
    }
    return 0;
}