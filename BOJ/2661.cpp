// 2661번_좋은수열
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int n;
string seq;
bool isPromising(){
    // 부분 수열이 동일한 것이 존재할 수 있는 조건의 최대 길이는 전체 수열의 절반
    int len = seq.length();
    for(int i=1; i<=len/2; ++i){
        // 방금 추가된 부분을 포함하도록 수열의 뒤에서부터 확인
        string sub1 = seq.substr(len-i, i);
        string sub2 = seq.substr(len-i*2, i);
        // 인접한 두 부분수열이 같으면 나쁜수열이므로 방금 추가된 부분을 제외
        if(sub1 == sub2) return false;
    }
    return true;
}
void makeSequence(int len){
    // 길이 만족하는 첫 수열은 나쁜수열이 아닌 가장 작은 수열이므로 출력 후 종료
    if(len == n){
        cout << seq;
        exit(0);
    }
    // 1, 2, 3중 하나 붙여보고 제거하는 과정을 반복함
    for(int i=1; i<=3; ++i){
        seq.push_back(i+'0');
        if(isPromising()) makeSequence(len+1); 
        seq.pop_back();
    }    
}
int main(){
    cin >> n;
    makeSequence(0);
    return 0;
}