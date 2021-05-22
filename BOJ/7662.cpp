// 7662번_이중 우선순위 큐
#include <iostream>
#include <set>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    F_I;
    int t, k, value;
    char c;
    cin >> t;
    while(t--){
        multiset <int> m; // 원소들이 오름차순으로 정렬됨
        cin >> k;
        while(k--){
            cin >> c >> value;
            if(c == 'I'){
                m.insert(value);
            }
            else if(c=='D' && !m.empty()){
                // erase()시 주소값을 인자로 줌
                // end()는 마지막 원소 다음의 주소값을 리턴하므로 하나 이전을 가리키도록 해야됨
                if(value == 1) m.erase(--m.end());
                else if(value == -1) m.erase(m.begin());
            }
        }
        // iterator로 set container에 저장된 원소에 접근 가능
        // iterator가 가리키는 원소의 값은 * 연산자로 읽을 수 있음
        if(!m.empty()) cout << *(--m.end()) << " " << *m.begin() << "\n";
        else cout << "EMPTY\n";
    }
    return 0;
}