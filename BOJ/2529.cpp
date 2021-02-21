// 2529번_부등호
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int k;
char sign[9];
bool isUsed[10]; 
vector<string> ans; // 부등호 관계를 만족하는 정수를 저장

bool CheckSign(char num1, char sign, char num2){
    if(sign == '<'){
        if(num1 < num2) return true;
    }else{
        if(num1 > num2) return true;
    }
    return false;
}

void MakeNumber(int cnt, string number){ 
    if(cnt == k+1){
        // k+1 자리 정수가 완성되면 벡터에 저장
        ans.push_back(number);
        return;
    }
    for(int i=0; i<=9; ++i){
        if(!isUsed[i]){
            // 첫번째 자리에 들어갈 수 이거나 부등호 관계를 만족하는 수를 문자열에 더함
            if((cnt == 0) || CheckSign(number[cnt-1], sign[cnt-1], i+'0')){         
                isUsed[i] = true;
                MakeNumber(cnt+1, number + to_string(i));
                isUsed[i] = false;
            }
        }
    }
}

int main(){
    cin >> k;
    for(int i=0; i<k; ++i) cin >> sign[i];
    MakeNumber(0, "");
    // 부등호 관계를 만족하는 k+1 자리의 정수들을 정렬한 뒤 최대, 최소 정수를 출력
    sort(ans.begin(), ans.end());
    cout << ans[ans.size()-1] << "\n" << ans[0] << "\n";
    return 0;
}