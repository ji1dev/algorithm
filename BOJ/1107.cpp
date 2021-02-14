// 1107번_리모컨
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
bool broken[10] = {false, };

// 살아있는 버튼으로 이동할 수 있는 채널인지 확인
bool verify(int ch){
    // 0번 채널에 대한 예외처리
    if(ch == 0){
        if(broken[0]) return false;
    }
    // 고장난 버튼의 숫자가 포함되어 있는지 확인
    int tmp;
    while(ch){
        tmp = ch%10;
        if(broken[tmp]) return false;
        ch /= 10;
    }
    return true;
}

// 주어진 채널 ch로 이동하기 위해 눌러야 하는 버튼의 최소 개수 구하기
int buttonPressed(int ch){
    
    // 누르는 횟수의 기본값을 +- 버튼만으로 이동하는 경우로 설정
    int btnCnt = abs(ch - 100);
    int compBtnCnt = 0;

    for(int i=0; i<=1000000; ++i){
        if(verify(i)){
            // 채널 i로 이동하기 위해 눌러야 하는 버튼의 개수
            compBtnCnt = to_string(i).length();
            // 목표 채널로 이동하기 위해 누르는 +-버튼의 횟수를 더해줌 
            compBtnCnt += abs(ch - i); 
            // 누르는 횟수의 최솟값 갱신
            if(btnCnt > compBtnCnt) btnCnt = compBtnCnt;
        }
    }
    return btnCnt;
}

int main(){
    int ch, m, b;
    int btnCnt = 0; 
    cin >> ch >> m; // 이동하려는 채널, 고장난 버튼의 개수
    for(int i=0; i<m; ++i){
        cin >> b; // 고장난 버튼
        broken[b] = true;
    }
    cout << buttonPressed(ch) << "\n";
    return 0;
}