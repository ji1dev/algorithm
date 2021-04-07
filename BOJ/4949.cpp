// 4949번_균형잡힌 세상
#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> s;
string str;
int check(){
    int len = str.length();
    for(int i=0; i<len; ++i){
        if(str[i] == '(' || str[i] == '['){
            s.push(str[i]);
        }
        else if(str[i] == ')' || str[i] == ']'){
            // 닫는 괄호 나왔는데 스택이 비어있으면 여는 괄호 쌍이 맞지 않는 것
            if(s.empty()) return false;
            if(s.top() == '(' && str[i] == ')') s.pop();
            else if(s.top() == '[' && str[i] == ']') s.pop();
            else return false;
        }
    }
    return s.empty();
}
int main(){
    while(1){
        getline(cin, str);
        if(str[0] == '.') break;
        if(check()) cout << "yes\n";
        else cout << "no\n";
        while(!s.empty()) s.pop();
    }
    return 0;
}