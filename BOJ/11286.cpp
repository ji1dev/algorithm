// 11286번_절댓값 힙
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
int main(){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    int n, value;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> value;
        if(value==0){
            if(!pq.empty()){
                // 우선순위 큐를 입력값의 절댓값을 기준으로 오름차순 정렬하도록 설정
                // top찍으면 절댓값 가장 작은 pair가 나옴
                cout << pq.top().second << "\n";
                pq.pop();
            }
            else
                cout << "0\n";
        }
        else{
            pq.push(make_pair(abs(value), value)); // pair의 first는 절대값, second는 원본값
        }
    }
    return 0;
}