// 14888번_연산자 끼워넣기
#include <iostream>
#include <algorithm>
#define MAX 1000000001
using namespace std;
int n, num[11], op_cnt[4], max_ans, min_ans;
int Calc(int n1, int n2, int op){
    if(op == 0) return n1+n2;
    else if(op == 1) return n1-n2;
    else if(op == 2) return n1*n2;
    else if(op == 3) return n1/n2;
    else return 0;
}
void mkExpr(int ans, int cnt){
    if(cnt == n){
        max_ans = max(max_ans, ans);
        min_ans = min(min_ans, ans);
        return;
    }
    for(int i=0; i<4; ++i){
        if(op_cnt[i] == 0) continue; // 모두 사용한 연산자는 넘어감
        op_cnt[i]--;
        mkExpr(Calc(ans, num[cnt], i), cnt+1); // 현재 결과, 다음 숫자, 연산자
        op_cnt[i]++;
    }
}
int main(){
    max_ans = -MAX;
    min_ans = MAX;
    cin >> n;
    for(int i=0; i<n; ++i) cin >> num[i];
    for(int i=0; i<4; ++i) cin >> op_cnt[i];
    mkExpr(num[0], 1); // 첫 숫자를 결과로 두고 연산자와 다음 숫자 이어붙임
    cout << max_ans << "\n" << min_ans;
    return 0;
}