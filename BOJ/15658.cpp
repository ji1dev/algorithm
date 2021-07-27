// 15658번_연산자 끼워넣기 (2)
#include <iostream>
#include <algorithm>
#define MAX 1000000001
using namespace std;
int n, min_r, max_r, num[11], op_cnt[4];
int mkRes(int n1, int op, int n2){
    if(op == 0) return n1+n2;
    else if(op == 1) return n1-n2;
    else if(op == 2) return n1*n2;
    else if(op == 3) return n1/n2;
    else return 0;
}
void mkExpr(int idx, int res){
    if(idx == n){
        // n개 숫자를 모두 사용한 식이 완성되면 결과를 계산하고 최댓값, 최솟값을 갱신
        max_r = max(max_r, res);
        min_r = min(min_r, res);
        return;
    }
    for(int i=0; i<4; ++i){
        if(op_cnt[i] == 0) continue; // 해당 연산자를 모두 사용했으면 넘어감
        op_cnt[i]--;
        mkExpr(idx+1, mkRes(res, i, num[idx])); // 현재 연산자를 추가해서 만든 식의 결과를 계산
        op_cnt[i]++;
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> num[i];
    for(int i=0; i<4; ++i) cin >> op_cnt[i];
    min_r = MAX;
    max_r = -MAX;
    mkExpr(1, num[0]); // 첫 번째 수는 이미 결과에 반영한 상태로 시작
    cout << max_r << "\n" << min_r;
    return 0;
}