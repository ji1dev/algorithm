// 13417번_카드 문자열
#include <iostream>
#include <deque>
using namespace std;
int t;
char c[1001];
int main(){
    cin >> t;
    while(t--){
        deque<char> dq;
        int n;
        cin >> n;
        for(int i=0; i<n; ++i){
            cin >> c[i];
            // 사전순으로 가장 빠른 문자열 만들기 위해 맨 앞 카드와 비교해서 
            // 같거나 빠르면 맨 앞, 느리면 맨 뒤에 넣어줌
            if(i == 0) dq.push_back(c[0]);
            else if(c[i] <= dq.front()) dq.push_front(c[i]);
            else dq.push_back(c[i]);
        }
        for(auto i=dq.begin(); i!=dq.end(); ++i) cout << *i;
        cout << "\n";
    }
    return 0;
}