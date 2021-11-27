// 1935번_후위 표기식2
#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<double> st;
string expr;
int n, val[26];
double ans;
int main(){
    cin >> n >> expr;
    for(int i=0; i<n; ++i) cin >> val[i];
    for(int i=0; i<expr.length(); ++i){
        if(expr[i]>='A' && expr[i]<='Z') st.push(val[expr[i]-'A']);
        else{
            // 연산자 나오면 피연산자 2개 스택에서 꺼내서 연산한 뒤 다시 스택에 push
            double ope = st.top();
            st.pop();
            if(expr[i] == '+') ope = st.top()+ope;
            else if(expr[i] =='-') ope = st.top()-ope;
            else if(expr[i] =='*') ope = st.top()*ope;
            else if(expr[i] =='/') ope = st.top()/ope;
            st.pop();
            st.push(ope);
        }
    }
    ans = st.top();
    printf("%.2f", ans);
    return 0;
}