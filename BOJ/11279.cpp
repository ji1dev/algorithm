// 11279번_최대 힙
#include <iostream>
#include <vector>
#include <queue>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    F_I;
    // 최대 힙은 부모노드의 값이 자식노드의 값보다 큼
    priority_queue<int> q;
    int n, tmp;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        if(!tmp){
            if(!q.empty()){
                // 큐 내부는 내림차순으로 정렬되어 있으므로 pop하면 가장 큰 값 리턴됨
                // 따라서 최대 힙과 같은 성질을 가짐
                cout << q.top() << "\n";
                q.pop();
            }
            else cout << 0 << "\n";
        }
        else{
            q.push(tmp);
        }
    }
    return 0;
}