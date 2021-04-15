// 1966번_프린터 큐
#include <iostream>
#include <queue>
using namespace std;
int main(){
    int t, n, target, priority, cnt;
    cin >> t;
    for(int tc=0; tc<t; ++tc){
        queue< pair<int, int> > q;
        priority_queue <int> pq;
        cnt = 0;
        cin >> n >> target;
        for(int i=0; i<n; ++i){
            cin >> priority;
            q.push(make_pair(i, priority)); // 문서의 위치와 우선순위 저장
            pq.push(priority); // 문서의 우선순위 저장
        }
        while(!q.empty()){
            int idx = q.front().first; // 현재 문서의 위치
            int pri = q.front().second; // 현재 문서의 우선순위
            q.pop();
            // 현재 문서가 가장 높은 우선순위라면 우선순위 큐에서 제거
            // 이때 제거 횟수를 세며, target번째 문서라면 저장된 횟수를 출력
            if(pq.top() == pri){
                pq.pop();
                cnt++;
                if(idx == target) break;
            }
            // 현재 문서가 가장 높은 우선순위가 아니라면 큐의 맨 뒤에 다시 삽입
            else q.push(make_pair(idx, pri));
        }
        cout << cnt << "\n";
    }
    return 0;
}