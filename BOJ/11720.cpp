// 11720번_숫자의 합
#include <iostream>
using namespace std;
int main(){
    int n, sum = 0;
    char num[100];
    cin >> n >> num;
    for(int i=0; i<n; ++i){
        // char 0~9는 ascii 코드 48부터 시작하므로 
        // '0'을 빼주면 int 0~9를 얻을 수 있음
        sum += num[i]-'0';
    }
    cout << sum << "\n";
    return 0;
}