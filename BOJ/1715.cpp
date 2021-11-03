// 1715번_카드 정렬하기
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, cnt;
priority_queue<int, vector<int>, greater<int> > pq;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        int size;
        cin >> size;
        pq.push(size);
    }
    // 항상 가장 작은 카드 묶음 2개를 골라 합쳐나가도록 우선순위큐로 카드 정보를 유지
    // 카드 묶음이 2개 이상일때만 묶음을 합침
    while(pq.size() > 1){
        int c1, c2, cmp;
        c1 = pq.top(); pq.pop();
        c2 = pq.top(); pq.pop();
        cmp = c1+c2;
        cnt += cmp;
        pq.push(cmp);
    }
    cout << cnt;
    return 0;
}