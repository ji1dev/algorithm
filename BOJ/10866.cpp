// 10866번_덱
#include <iostream>
#include <deque>
#include <string>
using namespace std;
int n, tmp;
string cmd;
deque<int> dq;
int size(){
    return dq.size();
}
int empty(){
    return dq.empty();
}
int pop_front(){
    if(!empty()){
        int ret = dq[0];
        dq.pop_front();
        return ret;
    }
    return -1;
}
int pop_back(){
    if(!empty()){
        int ret = dq[size()-1];
        dq.pop_back();
        return ret;
    }
    return -1;
}
int front(){
    if(!empty()) return dq[0];
    return -1;
}
int back(){
    if(!empty()) return dq[size()-1];
    return -1;
}
int main(){
    cin >> n;
    while(n--){
        cin >> cmd;
        if(cmd == "push_front"){
            cin >> tmp;
            dq.push_front(tmp);
        }else if(cmd == "push_back"){
            cin >> tmp;
            dq.push_back(tmp);
        }else if(cmd == "pop_front"){
            cout << pop_front() << "\n";
        }else if(cmd == "pop_back"){
            cout << pop_back() << "\n";
        }else if(cmd == "size"){
            cout << size() << "\n";
        }else if(cmd == "empty"){
            cout << empty() << "\n";
        }else if(cmd == "front"){
            cout << front() << "\n";
        }else if(cmd == "back"){
            cout << back() << "\n";
        }
    }
    return 0;
}