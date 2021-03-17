// 9012번_괄호
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int n, len = 0;
stack<int> st;
string paren;
bool check(){
    len = paren.length();
    for(int i=0; i<len; ++i){
        if(paren[i] == '('){
            // 여는 괄호 나오면 스택에 원소 추가
            st.push(1);    
        }
        else{
            // 닫는 괄호 나왔는데 스택이 비어있으면 여는 괄호가 모자란 것
            // 아니면 스택에서 여는 괄호 제거
            if(st.empty()) return false;
            else st.pop();
        }
    }
    return st.empty(); // 마지막에 스택이 비어있으면 괄호 쌍이 모두 맞은 것
}
int main(){
    cin >> n;
    while(n--){
        cin >> paren;   
        if(check()) cout << "YES\n";
        else cout << "NO\n";
        while(!st.empty()) st.pop(); // 스택 clear
    }
    return 0;
}