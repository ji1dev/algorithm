// 13305번_주유소
#include <iostream>
#define MAX 1000000000
using namespace std;
int main(){
    long long distance[100000] = {0, };
    long long price[100000] = {0, };
    long long low, sum = 0;
    int n;
    cin >> n;
    low = MAX;
    for(int i=0; i<n-1; ++i) cin >> distance[i];
    for(int i=0; i<n; ++i) cin >> price[i];
    for(int i=0; i<n-1; ++i){
        // 현재까지 가장 저렴한 리터당 가격으로 다음 주유소까지 갈 기름을 넣음
        if(price[i]<low) low = price[i];
        sum += low*distance[i];
    }
    cout << sum;
    return 0;
}