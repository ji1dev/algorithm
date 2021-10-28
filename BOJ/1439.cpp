// 1439번_뒤집기
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int zeroBlk, oneBlk;
string s;
int main(){
    cin >> s;
    // 0이 연속되는 구간, 1이 연속되는 구간의 개수를 각각 세고 구간의 개수가 더 적은 숫자를 뒤집음
    for(int i=0; i<s.length(); ++i){
        if(s[i] == '0') zeroBlk++;
        else oneBlk++;
        while(s[i] == s[i+1]) i++;
    }
    cout << min(zeroBlk, oneBlk);
    return 0;
}