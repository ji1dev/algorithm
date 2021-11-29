// 2075번_N번째 큰 수
#include <iostream>
#include <queue>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n;
priority_queue <int, vector<int>, greater<int> > pq;
int main(){
    F_IO;
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            int val;
            cin >> val;
            pq.push(val);
            if(pq.size() > n) pq.pop();
        }
    }
    cout << pq.top();
    return 0;
}