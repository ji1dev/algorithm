// 16953번_A → B
#include <iostream>
#include <queue>
#define MP make_pair
#define ll long long
using namespace std;
ll a, b, ans;
queue< pair<ll, ll> > q; // 값, 연산 횟수
void bfs(){
    q.push(MP(a, 0));
    while(!q.empty()){
        ll num = q.front().first;
        ll cnt = q.front().second;
        q.pop();
        if(num == b){
            ans = cnt+1;
            return;
        }
        // 메모리 초과를 피하기 위해 큐에 들어갈 값을 걸러줌
        if(num*2 <= b) q.push(MP(num*2, cnt+1));
        if(num*10+1 <= b) q.push(MP(num*10+1, cnt+1));
    }
    ans = -1; // 만들 수 없으면 -1
}
int main(){
    cin >> a >> b;
    ans = 987654321;
    bfs();
    cout << ans;
    return 0;
}