// 1874번_스택 수열
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
    int n, idx = 0, seq[100001] = {0, };
    stack<int> st;
    vector<char> v;
    cin >> n;
    for(int i=0; i<n; ++i) cin >> seq[i];
    // 1~n까지 스택에 push하며 pop조건을 만족하는지 확인
    // 스택 top이 입력된 수열의 idx번째 수와 같으면 pop
    for(int i=1; i<=n; ++i){
        st.push(i);
        v.push_back('+');     
        // 연속 pop도 가능하므로 반복문으로 처리 
        while(!st.empty() && (st.top() == seq[idx])){
            st.pop();
            v.push_back('-');
            idx++;
        }
    }
    if(!st.empty()) cout << "NO";
    else{
        for(int i=0; i<v.size(); ++i) 
            cout << v[i] << "\n";
    }    
    return 0;
}