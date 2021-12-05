// 2002번_추월
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int n, ans;
unordered_map<string, int> in;
vector<string> out;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        string s;
        cin >> s;
        in[s] = i;
    }
    for(int i=0; i<n; ++i){
        string s;
        cin >> s;
        out.push_back(s);
    }
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            // 늦게 들어간 차가 먼저 나오는 경우 추월 발생한 것
            if(in[out[i]] > in[out[j]]){
                ans++;
                break; // 찾으면 다음 순서로
            }
        }
    }
    cout << ans;
    return 0;
}