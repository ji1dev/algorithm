// 1918번_후위 표기식
#include <iostream>
#include <string>
#include <stack>
using namespace std;
string expr;
stack<char> op;
int main(){
    cin >> expr;
    for(int i=0; i<expr.length(); ++i){
        if(expr[i]>='A' && expr[i]<='Z') cout << expr[i];
        else{
            if(expr[i] == '('){
                op.push(expr[i]);
            }
            else if(expr[i] == ')'){
                // 여는 괄호 나올때까지 연산자 출력
                while(!op.empty() && op.top()!='('){
                    cout << op.top();
                    op.pop();
                }
                op.pop(); // 여는 괄호 pop
            }
            else if(expr[i]=='*' || expr[i]=='/'){
                // 같은 우선순위 연산자 먼저 출력하고, *, / 연산자 push
                while(!op.empty() && (op.top()=='*' || op.top()=='/')){
                    cout << op.top();
                    op.pop();
                }
                op.push(expr[i]);
            }
            else if(expr[i]=='+' || expr[i]=='-'){
                // 여는 괄호 나올때까지 연산자 출력하고, 낮은 우선순위 +, - 연산자 push
                while(!op.empty() && op.top()!='('){
                    cout << op.top();
                    op.pop();
                }
                op.push(expr[i]);
            }
        }
    }
    while(!op.empty()){ // 남은 연산자 모두 출력
        cout << op.top();
        op.pop();
    }
    return 0;
}