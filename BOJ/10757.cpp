// 10757번_큰 수 A+B
#include <iostream>
#include <string>
using namespace std;
int n1[10001], n2[10001];
void solve(string a, string b){
    string ans;
    // 자릿수 올림을 고려해서 맨 앞자리를 비워두고,
    // 둘 중 더 작은 숫자는 자릿수의 차이만큼 앞부분을 비워두고 변환함
    for(int i=0; i<a.length(); ++i) n1[i+1] = a[i]-'0';
    for(int i=0; i<b.length(); ++i) n2[i+1+(a.length()-b.length())] = b[i]-'0';

    // 끝 자리 부터 덧셈 연산 수행하면서 자릿수 올림 발생시 상위자리에 1더해주고 나머지만 결과로 사용
    for(int i=a.length(); i>=0; --i){
        int tmp = n1[i]+n2[i];
        if(tmp >= 10){
            tmp -= 10;
            n1[i-1]++;
        }
        ans += tmp+'0';
    }

    int s = ans.size()-1;
    if(ans[s] != '0') cout << ans[s]; // 자릿수 늘어난 경우
    for(int i=s-1; i>=0; --i) cout << ans[i];
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    if(s1.length() < s2.length()) solve(s2, s1); // a가 더 큰 숫자가 되도록 함
    else solve(s1, s2);
    return 0;
}