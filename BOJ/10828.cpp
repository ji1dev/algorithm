// 10828번_스택
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    int n;
    string cmd;
    stack<int> st;
    cin >> n;
    while(n--){
        cin >> cmd;
        if(cmd == "push"){
            int tmp;
            cin >> tmp;
            st.push(tmp);
        }
        else if(cmd == "pop"){
            if(!st.empty()){
                cout << st.top() << "\n";
                st.pop();
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if(cmd == "size"){
            cout << st.size() << "\n";
        }
        else if(cmd == "empty"){
            cout << st.empty() << "\n";
        }
        else if(cmd == "top"){
            if(!st.empty()) cout << st.top() << "\n";
            else cout << -1 << "\n";
        }
    }
    return 0;
}