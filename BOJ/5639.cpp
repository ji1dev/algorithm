// 5639번_이진 검색 트리
#include <iostream>
#define MAX 10001
using namespace std;
int cnt, pre[MAX], post[MAX];
void solve(int begin, int end){
    int tmp;
    if(begin >= end) return;
    for(tmp=begin+1; tmp<end; ++tmp){ // 현재 서브트리의 범위 내에서 루트보다 큰 값 나올때까지 탐색
        if(pre[begin] < pre[tmp]) break;
    }
    solve(begin+1, tmp); // 왼쪽 (begin+1 ~ tmp-1)
    solve(tmp, end); // 오른쪽 (tmp ~ end-1)
    cout << pre[begin] << " "; // 루트
}
int main(){
    int a;
    while(cin >> pre[cnt]) cnt++; // 전위순회 결과 입력
    solve(0, cnt);
    return 0;
}