// 4358번_생태학
#include <iostream>
#include <map>
#include <string>
using namespace std;
int cnt;
string s;
map <string, int> mp;
int main(){
    while(getline(cin, s)){
        mp[s]++;
        cnt++;
    }
    cout.precision(4); // 소수점 4째자리까지 반올림 처리
    cout << fixed; // 고정
    for(auto i:mp){
        cout << i.first << " " << ((double)i.second/cnt)*100 << "\n";
    }
    return 0;
}