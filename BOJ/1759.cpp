// 1759번_암호 만들기
#include <iostream>
#include <algorithm>
using namespace std;
int l, c, vowelCnt = 0;
char alpha[15], pw[15];
bool isUsed[15];
int ModifyCnt(int cnt, int idx, int mode){
    // 현재 암호에 포함된 모음의 개수를 증감
    if(pw[idx] == 'a' || pw[idx] == 'e' || pw[idx] == 'i' || pw[idx] == 'o' || pw[idx] == 'u'){
        if(mode == 1) cnt++;
        else if(mode == 0) cnt--;
    }
    return cnt;
}
void MakePassword(int idx, int vowelCnt){
    // 암호의 길이가 l이고 모음과 자음이 각각 1개, 2개 이상 포함되어 있으면 출력
    if(idx == l){
        if(vowelCnt >= 1){
            if(l-vowelCnt >= 2){
                for(int i=0; i<l; ++i){
                    cout << pw[i];
                }    
                cout << "\n";
                return;
            }
        }
        return;
    }
    // 입력 문자를 한번씩 사용하여 사전식으로 암호를 생성함
    // 암호에 문자가 추가-제거 될 때마다 모음의 개수를 갱신함
    for(int i=0; i<c; ++i){
        if(!isUsed[i]){
            if(pw[idx-1]<alpha[i]){
                pw[idx] = alpha[i];        
                isUsed[i] = true;
                vowelCnt = ModifyCnt(vowelCnt, idx, 1);       
                MakePassword(idx+1, vowelCnt);          
                isUsed[i] = false;
                vowelCnt = ModifyCnt(vowelCnt, idx, 0);
            }
        }
    }
}
int main(){
    // 암호의 길이 l, 입력 문자의 개수 c
    cin >> l >> c;
    for(int i=0; i<c; ++i)
        cin >> alpha[i];
    sort(alpha, alpha+c);
    MakePassword(0, 0);
    return 0;
}