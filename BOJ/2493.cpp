// 2493번_탑
#include <iostream>
#include <stack>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MP make_pair
using namespace std;
int n, height;
stack< pair<int, int> > st; // 탑 순서와 높이
int main(){
    F_I;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> height;
        while(!st.empty()){
            int prev_tower = st.top().first;
            int prev_height = st.top().second;
            if(prev_height > height){ // 이전 탑이 더 높은 경우만 수신 가능 (꼭대기에는 송신기가 있으므로)
                cout << prev_tower << " ";
                break; // 수신 탑 찾으면 탈출
            }
            st.pop(); // 현재 탑 보다 낮은 탑은 pop
        }
        if(st.empty()) cout << "0 "; // 신호 수신할 탑 없으면 0 출력
        st.push(MP(i+1, height));
    }
    return 0;
}