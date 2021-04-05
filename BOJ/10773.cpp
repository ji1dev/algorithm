// 10773번_제로
#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> s;
    int k, tmp, sum = 0;
    cin >> k;
    while(k--){
        cin >> tmp;
        if(tmp == 0) s.pop();
        else s.push(tmp);
    }
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum;
    return 0;
}