// 2407번_조합
// 문자열 파싱해서 덧셈 구현 (10757번_큰 수 A+B 참고)
#include <iostream>
#include <string>
#define MAX 101
using namespace std;
int n, m;
string dp[MAX][MAX];
string add(string a, string b){
    string res = "";
    if(a.length() < b.length()){ // 두 숫자 문자열의 길이 맞춰주기
        while(a.length() != b.length()) a = '0'+a;
    }
    else{
        while(a.length() != b.length()) b = '0'+b;
    }
    // 끝 자리부터 덧셈 연산, 올림 발생시 나머지를 현재 자리의 수로 사용하고 다음 자리 계산시 +1
    int tmp = 0;
    for(int i=a.length()-1; i>=0; --i){
        tmp += (a[i]-'0')+(b[i]-'0');
        res = to_string(tmp%10)+res;
        if(tmp >= 10) tmp = 1; // 올림 발생
        else tmp = 0;
    }
    // 올림으로 인해 새로운 자리 생성되는 경우
    if(tmp == 1) return '1'+res;
    return res;
}
string combination(int n, int m){
    // 전부 고르거나 아무것도 안고르는 경우는 한가지로 고정
    // 재귀로 n 선택 후 나머지 n-1개 중 m-1개 선택하는 경우, n 선택하지 않고 나머지 n-1개 중 m개를 선택하는 경우의 합을 구함
    if((n == m) || (m == 0)) return "1";
    if(dp[n][m] != "") return dp[n][m]; // 이미 계산된 값이면 바로 리턴
    else{
        dp[n][m] = add(combination(n-1, m-1), combination(n-1, m));
        return dp[n][m];
    }
}
int main(){
    cin >> n >> m;
    cout << combination(n, m);
}