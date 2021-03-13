// 11866번_요세푸스 문제 0
#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, k, pos;
    queue<int> q;
    cin >> n >> k;
    for(int i=0; i<n; ++i) q.push(i+1);
    cout << "<";
    // 현 위치에서 k-1자리 이동하기 위해 큐의 가장 앞 원소를 k-1회 뒤로 옮김
    // 이후 큐가 빌 때 까지 가장 앞 원소를 pop하면 요세푸스 순열을 구할 수 있음
    while(!q.empty()){
        for(int i=0; i<k-1; ++i){
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if(!q.empty()) cout << ", ";
    }
    cout << ">";
    return 0;
}