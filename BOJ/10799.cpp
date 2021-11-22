// 10799번_쇠막대기
#include <iostream>
#include <string>
using namespace std;
string s;
int rod, piece;
int main(){
    cin >> s;
    for(int i=0; i<s.length(); ++i){
        if(s[i] == '('){
            if(s[i+1] == ')'){ // 레이저
                piece += rod; // 겹쳐진 막대 개수만큼 조각남
                i++;
            }
            else{ // 새로 겹쳐지는 막대
                rod++;
            }
        }
        else{ // 겹쳐진 막대의 끝
            piece++; // 막대 끝나면서 마지막 조각 나옴
            rod--;
        }
    }
    cout << piece;
    return 0;
}