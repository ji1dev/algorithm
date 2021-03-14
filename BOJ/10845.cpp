// 10845번_큐
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, num;
vector<int> q;
string cmd;
int empty(){
    if(q.empty()) return 1;
    else return 0;
}
void push(int input){
    q.push_back(input);
}
int pop(){
    if(!empty()){
        int tmp = q[0];
        q.erase(q.begin());
        return tmp;
    }
    return -1;
}
int size(){
    return q.size();
}
int front(){
    if(!empty()) return q[0];
    else return -1;
}
int back(){
    if(!empty()) return q[q.size()-1];
    else return -1;
}
int main(){
    cin >> n;
    while(n--){
        cin >> cmd;
        if(cmd == "push"){
            cin >> num;
            push(num);
        }else if(cmd == "pop"){
            cout << pop() << "\n";
        }else if(cmd == "empty"){
            cout << empty() << "\n";
        }else if(cmd == "size"){
            cout << size() << "\n";
        }else if(cmd == "front"){
            cout << front() << "\n";
        }else if(cmd == "back"){
            cout << back() << "\n";
        }
    }
    return 0;
}