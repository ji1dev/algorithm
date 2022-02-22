// 10809번_알파벳 찾기
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int alpha[26], len;
    char word[101];
    memset(alpha, -1, 26 * sizeof(int));
    cin >> word;
    len = strlen(word);
    for(int i=0; i<len; ++i){
        if(alpha[word[i]-'a'] == -1) alpha[word[i]-'a'] = i;   
    }
    for(int i=0; i<26; ++i){
        cout << alpha[i] << " ";
    }
    return 0;
}