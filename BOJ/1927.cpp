// 1927번_최소 힙
#include <iostream>
#include <queue>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    F_I;
    // 자료형, 컨테이너<자료형>, 비교연산<자료형>
    // 우선순위 큐 내부를 오름차순으로 정렬하기 위해 greater사용
    priority_queue<int, vector<int>, greater<int> > pq; 
    int n, x;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> x;
        if(!x){
            // x가 0이면 큐에서 가장 작은 값 출력
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            }
            else{
                cout << 0 << "\n";
            }
        }
        else{
            pq.push(x);
        }
    }
    return 0;
}