// 1021번_회전하는 큐
#include <iostream>
#include <deque>
using namespace std;
int n, m, ans;
deque<int> dq;
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i) dq.push_back(i);
    while(m--){
        int t, loc;
        cin >> t;
        for(int i=0; i<dq.size(); ++i){
            if(dq[i] == t){
                loc = i;
                break;
            }
        }
        if(loc <= (dq.size()-loc)){ // 2번 연산 (왼쪽 이동)
            while(dq.front() != t){
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
            dq.pop_front(); // 이동 마친 뒤 원소 뽑아냄
        }
        else{ // 3번 연산 (오른쪽 이동)
            while(dq.back() != t){
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
            dq.pop_back();
            ans++; // 오른쪽으로 가는 경우 덱의 back 기준으로 보기 때문에 +1회
        }
    }
    cout << ans;
    return 0;
}