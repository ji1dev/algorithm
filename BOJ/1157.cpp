// 1157번_단어 공부
// 첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 
// 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char word[1000001];
    int alpha[26], index, maxCnt = 0, len, flag = 0;
    scanf("%s", word);
    len = strlen(word);
    for(int i=0; i<len; ++i){
        index = word[i]-'A';
        if(index >= 32 && index <= 58) index -= 32;
        alpha[index]++;
    }
    for(int i=0; i<26; ++i){
        if(alpha[i] >= maxCnt){
            if(alpha[i] == maxCnt){
                flag = 1;
            }else{
                flag = 0;
                index = i;
                maxCnt = alpha[i];
            }
        }
    }
    if(flag) printf("?");
    else printf("%c\n", index+'A');
    return 0;
}