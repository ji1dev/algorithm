// 4889번_안정적인 문자열
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int o;
string s;
int main(){
    while(1){
        stack<char> st;
        int change = 0;
        cin >> s;
        if(s[0] == '-') break;
        for(int i=0; i<s.length(); ++i){
            // 스택 비어있는데 닫는 괄호 들어오면 여는 괄호로 변경
            if(st.empty() && s[i]=='}'){
                st.push('{');
                change++;
            }
            else if(s[i] == '{') st.push('{');
            else st.pop();
        }
        // 닫는 괄호 나오면 pop하므로, 문자열 끝까지 확인 후 스택의 크기는 남아있는 여는 괄호 개수임
        // 따라서 그 중 절반만큼 닫는 괄호로 바꿔줘야 안정적이므로 연산 횟수를 증가시켜줌
        change += st.size()/2;
        cout << ++o << ". " << change << "\n";
    }
    return 0;
}