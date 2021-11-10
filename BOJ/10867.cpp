// 10867번_중복 빼고 정렬하기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> v;
bool visited[2001];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        int a;
        cin >> a;
        // 절댓값 1000보다 작거나 같은 정수이므로 
        // -1000을 0으로 잡고 중복 걸러주기
        if(!visited[a+1000]){
            v.push_back(a);
            visited[a+1000] = true;
        }
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); ++i){
        cout << v[i] << " ";
    }
    return 0;
}