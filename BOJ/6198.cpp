// 6198번_옥상 정원 꾸미기
#include <iostream>
#include <stack>
#define ll long long
using namespace std;
int n;
ll ans;
stack<ll> st;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        int h;
        cin >> h;
        // 새 건물 높이가 들어와도 스택 내부를 내림차순으로 유지되도록 처리
        // 이 때 스택 크기는 새로 들어온 건물의 옥상을 확인할 수 있는 건물의 개수임
        while(!st.empty() && st.top()<=h) st.pop();
        ans += st.size();
        st.push(h);
    }
    cout << ans;
    return 0;
}