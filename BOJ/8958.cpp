// 8958번_OX퀴즈
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char str[80];
    int n, cnt, score;
    cin >> n;
    while(n--){
        score = 0; 
        cnt = 0;
        cin >> str;
        for(int i=0; i<strlen(str); ++i){
            if(str[i] == 'O'){
                cnt++;
                score += cnt;          
            }else{
                cnt = 0;
            }
        }
        cout << score << "\n";
    }
    return 0;
}