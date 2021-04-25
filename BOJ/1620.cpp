// 1620번_나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <string>
#include <map>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string c[100001];
map<string, int> pm;
int main(void){
    F_I;
    int n, m;
    string tmp;
    cin >> n >> m;
    for (int i=1; i<=n; ++i){
        cin >> tmp;
        pm.insert(make_pair(tmp, i));
        c[i] = tmp;
    }
    for (int i=0; i<m; ++i){
        cin >> tmp;
        // 숫자 입력이면 c배열에서 이름 찾기
        // 문자 입력이면 map에서 숫자 찾기
        if(isdigit(tmp[0])) cout << c[stoi(tmp)] << "\n";
        else cout << pm[tmp] << "\n";
    }
}
