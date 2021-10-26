// 2847번_게임을 만든 동준이
#include <iostream>
using namespace std;
int n, ans, score[101];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> score[i];
    for(int i=n-1; i>0; --i){
        // 점수 오름차순 만족하도록 최소한으로 점수를 내림
        if(score[i] <= score[i-1]){
            int d = score[i-1]-score[i]+1;
            score[i-1] -= d;
            ans += d;
        }
    }
    cout << ans;
    return 0;
}