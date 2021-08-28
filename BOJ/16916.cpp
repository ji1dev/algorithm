// 16916번_부분 문자열
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int t_len, p_len;
string text, pattern;
vector<int> pi;
void failureFunc(){
    // pi[i] = 패턴의 0~i까지 부분 문자열에서 접두사-접미사가 일치할 때의 길이
    // 불일치 발생 시 j값이 뛰어야 할 위치를 미리 계산
    int j = 0;
    pi.resize(p_len, 0);
    for(int i=1; i<p_len; ++i){
        while(j>0 && pattern[i]!=pattern[j]) j = pi[j-1];
        if(pattern[i] == pattern[j]) pi[i] = ++j;
    }
}
bool KMP(){
    int j = 0;
    failureFunc();
    for(int i=0; i<t_len; ++i){
        // 불일치 발생하면 미리 계산한 실패함수 값으로 j를 되돌림, 이 과정에서 일치하는 문자가 없으면 결국 j=0까지 돌아감
        // 일치하는 문자가 나오면 j값을 증가시키고, j값이 패턴의 길이까지 증가하면 문자열에 패턴이 포함되어 있다는 뜻이므로 true리턴
        while(j>0 && text[i]!=pattern[j]) j = pi[j-1];
        if(text[i] == pattern[j]){
            if(j == p_len-1) return true;
            else j++;
        }
    }
    return false;
}
int main(){
    cin >> text >> pattern;
    t_len = text.length();
    p_len = pattern.length();
    cout << KMP();
    return 0;
}