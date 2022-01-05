// 16974번_레벨 햄버거
#include <iostream>
#define ll long long
using namespace std;
int n;
ll x, hb[51], p[51];
ll solve(int n, ll x){ // x장 먹었을때 버거 구성 변화에 따라 분기
    if(n == 0) // 레벨-0 버거는 패티만으로 구성
        return x;
    else if(x == 1) // 버거 맨 아래는 번
        return 0;
    else if(x <= 1+hb[n-1]) // 맨 아래 번 먹고 이전 레벨 버거 확인
        return solve(n-1, x-1);
    else if(x <= 1+hb[n-1]+1) // (이전레벨 버거의 패티)+중간 패티
        return p[n-1]+1; 
    else if(x <= 1+hb[n-1]+1+hb[n-1]) // 번+(이전레벨 버거)+중간 패티 먹고 이전 레벨 버거 확인
        return p[n-1]+1+solve(n-1, x-(1+hb[n-1]+1));
    else // 버거 전체 먹음
        return p[n-1]+1+p[n-1];
}
int main(){
    cin >> n >> x;
    hb[0] = 1; // 레벨-0 버거의 재료는 패티 하나
    p[0] = 1;
    for(int i=1; i<=n; ++i){
        hb[i] = 1+hb[i-1]+1+hb[i-1]+1; // 번+(이전레벨 버거)+패티+(이전레벨 버거)+번
        p[i] = p[i-1]+1+p[i-1]; // (이전레벨 버거의 패티)+패티+(이전레벨 버거의 패티)
    }
    cout << solve(n, x); // x개 먹음
    return 0;
}