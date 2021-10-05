// 1662번_압축
#include <iostream>
#include <string>
#include <stack>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string s;
stack<int> st;
int paren[51];
int decompress(int begin, int end){
    int len = 0;
    for(int i=begin; i<end; ++i){
        // 괄호 내부의 문자열 길이를 재귀로 확인
        if(s[i] == '('){
            int k = s[i-1]-'0';
            len--; // k값은 문자열 길이에서 제외
            len += k*decompress(i+1, paren[i]);
            i = paren[i]; // 닫는 괄호 다음 문자부터 이어서 확인
            continue;
        }
        len++;
    }
    return len;
}
int main(){
    F_IO;
    cin >> s;
    for(int i=0; i<s.length(); ++i){
        if(s[i] == '(') st.push(i);
        else if(s[i] == ')'){
            paren[st.top()] = i; // 괄호 쌍 기록
            st.pop();
        }
    }
    cout << decompress(0, s.length());
    return 0;
}