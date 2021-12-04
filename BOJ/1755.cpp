// 1755번_숫자놀이
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MP make_pair
using namespace std;
int n, m;
string s[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<pair<string, int> > v;
int main(){
    cin >> n >> m;
    for(int i=n; i<=m; ++i){
        if(i >= 10) v.push_back(MP(s[i/10]+" "+s[i%10], i));
        else v.push_back(MP(s[i], i));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); ++i){
        cout << v[i].second << " ";
        if((i+1)%10 == 0) cout << "\n";
    }
    return 0;
}