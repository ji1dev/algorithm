// 2161번_카드1
#include <iostream>
#include <queue>
using namespace std;
int n;
queue<int> q;
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) q.push(i);
    // 맨 위 카드 버리고 그다음 카드를 제일 아래로 옮기는 과정 반복
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return 0;
}