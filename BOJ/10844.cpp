// 10844번_쉬운 계단 수
// 인접한 모든 자리수의 차이가 1이 나는 수를 계단 수라고 함
#include <iostream>
#define M 1000000000
using namespace std;
int main(){
    int n, d[101][10], cnt = 0;
    cin >> n;
    
    // 길이가 1인 수에 대한 초기값 설정
    d[1][0] = 0;
    for(int j=1; j<=9; ++j) d[1][j] = 1;

    // d[i][j] = j로 끝나는 i자리 계단수의 개수
    for(int i=2; i<=n; ++i){
        for(int j=0; j<=9; ++j){
            // 0으로 끝나는 계단수는 바로 앞 자리의 수가 +1인 경우만 가능 
            if(j == 0) d[i][j] = d[i-1][j+1];

            // 9로 끝나는 계단수는 바로 앞 자리의 수가 -1인 경우만 가능
            else if(j == 9) d[i][j] = d[i-1][j-1];

            // 1~8은 인접 자리수 차이가 +-1인 경우 모두 가능
            else d[i][j] = (d[i-1][j-1]+d[i-1][j+1])%M;
        }
    }
    for(int j=0; j<=9; ++j) cnt = (cnt+d[n][j])%M;
    cout << cnt;
    return 0;
}