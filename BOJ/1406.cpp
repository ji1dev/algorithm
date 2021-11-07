// 1406번_에디터
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int m;
string s;
stack<char> cleft, cright; // 커서 기준 왼쪽, 오른쪽
int main(){
    cin >> s;
    for(int i=0; i<s.length(); ++i){
        cleft.push(s[i]);
    }
    cin >> m;
    while(m--){
        char cmd;
        cin >> cmd;
        if(cmd == 'L'){ // 커서 왼쪽으로 이동
            if(cleft.empty()) continue;
            cright.push(cleft.top());
            cleft.pop();
        }
        else if(cmd == 'D'){ // 커서 오른쪽으로 이동
            if(cright.empty()) continue;
            cleft.push(cright.top());
            cright.pop();
        }
        else if(cmd == 'B'){ // 커서 왼쪽 문자 삭제
            if(cleft.empty()) continue;
            cleft.pop();
        }
        else if(cmd == 'P'){ // 커서 왼쪽에 문자 추가
            char tmp;
            cin >> tmp;
            cleft.push(tmp);
        }
    }
    while(!cleft.empty()){ // 커서 왼쪽 문자들의 출력 순서를 맞춰줌
        cright.push(cleft.top());
        cleft.pop();
    }
    while(!cright.empty()){
        cout << cright.top();
        cright.pop();
    }
    return 0;
}