// 17298번_오큰수
#include <iostream>
#include <stack>
#include <memory.h>
#define MP make_pair
using namespace std;
int n, ans[1000001];
stack<pair<int, int> > st;
int main(){
    cin >> n;
    memset(ans, -1, sizeof(ans));
    for(int i=0; i<n; ++i){
        int val;
        cin >> val;
        if(st.empty()){
            st.push(MP(val, i));
        }
        else{
            while(val > st.top().first){ // 본인보다 큰 수 나올때까지 스택 확인
                ans[st.top().second] = val; // 현재 스택 top에 있는 원소의 NGE 저장
                st.pop();
                if(st.empty()) break; // 전부 빠지면 탈출
            }
            st.push(MP(val, i)); // 본인보다 작은 원소의 NGE 모두 저장한 뒤 push
        }
    }
    for(int i=0; i<n; ++i) cout << ans[i] << " ";
    return 0;
}