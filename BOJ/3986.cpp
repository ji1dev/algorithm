// 3986번_좋은 단어
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int n, ans;
string s;
int main(){
    // 모든 문자에 대해 같은 문자끼리 겹치지 않게 아치형 곡선을 그리기 위해 양 끝단에 있는 문자를 생각
    // 스택의 top에 있는 문자와 입력 문자가 같으면 곡선 그려지므로 pop
    // 결과적으로 모든 문자를 판단한 뒤 스택이 비어있다면 모든 문자가 곡선으로 이어질 수 있다는 것
    cin >> n;
    while(n--){
        stack<char> st;
        cin >> s;
        for(int i=0; i<s.length(); ++i){
            if(!st.empty()){
                if(st.top() == s[i]) st.pop();
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }
        if(st.empty()) ans++;
    }
    cout << ans;
    return 0;
}