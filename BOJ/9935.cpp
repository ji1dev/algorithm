// 9935번_문자열 폭발
#include <iostream>
#include <string>
using namespace std;
string str, bomb;
char ans[1000001];
int idx;
int main(){
    cin >> str >> bomb;
    for(int i=0; i<str.length(); ++i){
        ans[idx++] = str[i]; // 새 문자열에 원본 문자 하나 추가
        if(idx < bomb.length()-1) continue; // 새 문자열이 폭탄보다 짧으면 넘어감
        if(ans[idx-bomb.length()] == bomb[0]){ // 폭탄의 첫 문자와 일치하는 부분 나오면 검사 시작
            bool isPop = true;
            for(int j=1; j<bomb.length(); ++j){
                // 폭탄과 다른 문자가 있으면 넘어감
                if(ans[idx-bomb.length()+j] != bomb[j]){
                    isPop = false;
                    break;
                }
            }
            if(isPop) idx -= bomb.length(); // 폭탄과 같은 부분이 있으면 폭탄 길이만큼 idx감소
        }
    }
    if(idx){
        for(int i=0; i<idx; ++i) cout << ans[i];
    }
    else cout << "FRULA"; // idx가 0이면 모든 문자가 폭발한 것
    return 0;
}