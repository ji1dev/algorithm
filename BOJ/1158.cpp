// 1158번_요세푸스 문제
#include <iostream>
#include <queue>
using namespace std;
int n, k;
queue<int> q;
int main(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) q.push(i);
    cout << "<";
    while(q.size() > 1){
        // k번째 사람을 제거되는 순서대로 출력하는 (N, K) 요세푸스 순열
        for(int i=0; i<k-1; ++i){
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";
    return 0;
}