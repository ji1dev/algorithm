// 2531번_회전 초밥
#include <iostream>
#include <algorithm>
using namespace std;
int n, d, k, c, ans, dish[33001];
int main(){
    cin >> n >> d >> k >> c;
    for(int i=0; i<n; ++i) cin >> dish[i];
    for(int i=0; i<n; ++i){
        bool cp = true, visited[3001] = {false, };
        int eat = k;
        for(int j=i; j<i+k; ++j){ // 슬라이딩 윈도우로 k개씩 확인
            if(visited[dish[j%n]]) eat--; // 쿠폰 고려하지 않고 k개 초밥 고르고, 중복인 초밥은 제외
            else visited[dish[j%n]] = true;
            if(dish[j%n] == c) cp = false; // 쿠폰의 초밥이 중복이면 사용 X
        }
        if(cp) eat++;
        ans = max(ans, eat);
    }
    cout << ans;
    return 0;
}