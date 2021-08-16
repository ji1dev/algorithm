// 1062번_가르침
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;
int n, k, ans, teach, word_b[51];
char essential[] = {'a', 'c', 'i', 'n', 't'};
string word;
void dfs(int alpha, int cnt){
    if(cnt == k){
        int read = 0;
        for(int i=0; i<n; ++i){
            // 가르친 문자들로 읽을 수 있는 단어의 개수를 셈
            if((word_b[i]&teach) == word_b[i]) read++;
        }
        ans = max(ans, read);
        return;
    }
    for(int i=alpha; i<26; ++i){
        if(teach & (1<<i)) continue; // 이미 가르친 문자 통과
        teach |= (1<<i);
        dfs(i+1, cnt+1); // 가르친 문자 다음부터 확인
        teach &= ~(1<<i);
    }
}
int main(){
    cin >> n >> k;
    if(k<5 || k==26){ // 모든 단어 읽을 수 있거나, 아무것도 읽을 수 없는 경우
        cout << (k==26 ? n : 0);
        exit(0);
    }
    for(int i=0; i<n; ++i){
        cin >> word;
        for(int j=0; j<word.length(); ++j){
            word_b[i] |= (1<<(word[j]-'a')); // 단어에 포함된 문자 마스킹
        }   
    }
    for(int i=0; i<5; ++i) teach |= (1<<(essential[i]-'a')); // 필수 문자 마스킹
    dfs(0, 5); // 알파벳 순서, 가르친 문자 개수
    cout << ans;
    return 0;
}