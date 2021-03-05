// 1181번_단어 정렬
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(string s1, string s2){
    if((s1.length() - s2.length()) == 0) return s1 < s2;
    return s1.length() < s2.length();
}
int main(){
    int n;
    string tmp;
    vector<string> wd;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        wd.push_back(tmp);
    }
    stable_sort(wd.begin(), wd.end(), comp);
    wd.erase(unique(wd.begin(), wd.end()), wd.end());
    for(int i=0; i<wd.size(); ++i){
        cout << wd[i] << "\n";
    }
    return 0;
}