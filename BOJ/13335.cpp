// 13335번_트럭
#include <iostream>
#include <queue>
#define MP make_pair
using namespace std;
int n, w, l, idx, cnt, cur, elapsed, trucks[1000];
queue<int> q;
int main(){
    cin >> n >> w >> l;
    for(int i=0; i<n; ++i){
        cin >> trucks[i];
    }
    // n대 트럭 모두 지나갈 때 까지 loop
    while(cnt != n){
        // 다리를 지난 트럭이 생기는 경우
        if(q.size() == w){
            int weight = q.front();
            q.pop();
            // 실제 트럭이 지나간 경우
            if(weight > 0){
                cur -= weight;
                cnt++; // 다리를 지나간 트럭++
            }
        }
        // (현재 올라간 트럭 무게 + 새 트럭 무게) <= 다리 최대하중 인 경우
        if(cur+trucks[idx] <= l){
            q.push(trucks[idx]);
            cur += trucks[idx];
            idx++;
        }
        else q.push(0); // 새 트럭 못올리는 경우 큐 밀어내기용 무게 0짜리 push
        elapsed++;
    }
    cout << elapsed;
    return 0;
}