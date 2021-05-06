// 17219번_비밀번호 찾기
#include <iostream>
#include <map>
#include <string>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    F_I;
    map <string, string> passwd;
    int n, m;
    string url, pass;
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> url >> pass;
        passwd.insert(make_pair(url, pass));
    }
    for(int i=0; i<m; ++i){
        cin >> url;
        cout << passwd[url] << "\n";
    }
    return 0;
}