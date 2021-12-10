// 5568번_카드 놓기
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;
int n, k;
bool visited[11];
string card[11];
set<string> ans;
vector<string> tmp;
void dfs(int cnt){
    // 개수만큼 뽑으면 가로로 나란히 놓아서 정수를 만듦
    if(cnt == k){
        string s;
        for(int i=0; i<tmp.size(); ++i){
            s += tmp[i];
        }
        ans.insert(s);
        return;
    }
    for(int i=0; i<n; ++i){
        if(visited[i]) continue;
        visited[i] = true;
        tmp.push_back(card[i]);
        dfs(cnt+1);
        tmp.pop_back();
        visited[i] = false;
    }
}
int main(){
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> card[i];
    }
    dfs(0);
    cout << ans.size(); // 만든 정수의 개수
    return 0;
}