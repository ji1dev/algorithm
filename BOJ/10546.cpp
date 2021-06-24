// 10546번_배부른 마라토너
#include <iostream>
#include <map>
#include <string>
using namespace std;
int n;
string s;
map< string, int > m;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> s;
        // map에 이미 같은 key(이름) 존재하면 cnt++, 아니면 1로 value 설정
        if(m.find(s) == m.end()) m[s] = 1;
        else m[s]++;
    }
    for(int i=0; i<n-1; ++i){
        cin >> s;
        // map에 입력 key존재하면 cnt--
        if(m.find(s) != m.end()) m[s]--;
    }
    for(auto iter : m){ // map내부를 iterator를 이용해서 순회
        // cnt가 0이 아니면 완주하지 못한 사람
        if(iter.second != 0) cout << iter.first;
    }
    return 0;
}