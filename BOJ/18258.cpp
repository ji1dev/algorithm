// 18258번_큐 2
#include <iostream>
#include <queue>
#include <string>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n;
queue<int> q;
int main(){
    F_IO;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s == "push"){
            int val;
            cin >> val;
            q.push(val);
        }
        else if(s == "pop"){
            if(!q.empty()){
                cout << q.front() << "\n";
                q.pop();
            }
            else cout << -1 << "\n";
        }
        else if(s == "size") cout << q.size() << "\n";
        else if(s == "empty") cout << q.empty() << "\n";
        else if(s == "front"){
            if(!q.empty()) cout << q.front() << "\n";
            else cout << -1 << "\n";
        }
        else if(s == "back"){
            if(!q.empty()) cout << q.back() << "\n";
            else cout << -1 << "\n";
        }
    }
    return 0;
}