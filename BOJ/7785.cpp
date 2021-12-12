// 4673번_셀프 넘버
#include <iostream>
#include <map>
#include <string>
using namespace std;
int n;
map<string, string, greater<string> > m; // map을 value기준 내림차순으로 저장
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        string name, log;
        cin >> name >> log;
        m[name] = log;        
    }
    for(auto i=m.begin(); i!=m.end(); ++i){
        if(i->second == "enter") cout << i->first << "\n";
    }
    return 0;
}