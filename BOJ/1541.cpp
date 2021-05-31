// 1541번_잃어버린 괄호
#include <iostream>
#include <string>
using namespace std;
int main(){
    string expr, num = "";
    bool isMinus = false;
    int sum = 0;
    cin >> expr;
    // '+'기호로 묶이는 숫자는 먼저 전부 더하고, '-'기호로 묶이는 숫자는 나중에 처리
    // '-'기호 뒤에 괄호를 치면 최솟값이 됨
    for(int i=0; i<=expr.length(); ++i){
        if(expr[i]>='0' && expr[i]<='9'){
            num += expr[i];
        }
        else{
            if(isMinus) sum -= stoi(num); // '-'기호 나왔으면 이후의 숫자는 뺌 (괄호를 침)
            else sum += stoi(num); // '-'기호 안나왔으면 현재 숫자를 더함
            if(expr[i] == '-') isMinus = true; // '-'기호 이후의 숫자는 빼도록 flag활성화
            num = ""; // 새 숫자 시작하도록 초기화
        }
    }
    cout << sum;
    return 0;
}