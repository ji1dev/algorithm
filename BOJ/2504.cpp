// 2504번_괄호의 값
#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<char> st;
string p;
int Calc(){
    int value = 1, ans = 0;
    int len = p.length();
    for(int i=0; i<len; ++i){
        if(p[i] == '('){
            st.push(p[i]); // 바깥 괄호의 값은 내부 괄호의 값들에 곱해지므로 괄호 종류에 맞춰 미리 곱해둠
            value *= 2;
        }
        else if(p[i] == '['){
            st.push(p[i]);
            value *= 3;
        }
        else if(p[i] == ')'){
            // 스택 비어있거나 괄호 쌍 맞지 않으면 올바른 괄호열이 아님
            if(st.empty() || st.top()!='(') return 0;
            if(st.top() == '('){ // 괄호 쌍 맞는 경우
                // 현재 닫는 괄호가 가장 내부의 괄호인 경우 값을 더해줌
                // 아니면 바깥 괄호를 닫는 것이므로 생략
                if(p[i-1] == '(') ans += value;
                st.pop();
                value /= 2; // 한 괄호 쌍의 값을 구했으면 괄호 종류에 맞춰 값을 나눠줌
            }
        }
        else if(p[i] == ']'){
            if(st.empty() || st.top()!='[') return 0;
            if(st.top() == '['){
                if(p[i-1] == '[') ans += value;
                st.pop();
                value /= 3;
            }
        }
    }
    // 괄호열 모두 확인했는데 스택에 남아있는게 있으면 올바르지 않은 괄호열
    if(!st.empty()) return 0;
    return ans;
}
int main(){
    cin >> p;
    cout << Calc();
    return 0;
}