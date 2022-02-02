// 2138번_전구와 스위치
#include <iostream>
#include <string>
#include <algorithm>
#define INF 987654321
#define TGL(i) (tmp[i]=='0')?'1':'0'
using namespace std;
int n, ans;
string from, to;
void test(bool first){
    string tmp = from;
    int cnt = 0;
    if(first){ // 첫 스위치 누르는 경우
        cnt++;
        tmp[0] = TGL(0); // 전구 상태 토글
        tmp[1] = TGL(1);
    }
    // 현재 (i-1)번째 전구가 원하는 결과와 다르면 i번째 스위치를 눌러야됨
    for(int i=1; i<n; ++i){
        if(tmp[i-1] != to[i-1]){
            cnt++;
            tmp[i-1] = TGL(i-1);
            tmp[i] = TGL(i);
            if(i+1 < n) tmp[i+1] = TGL(i+1);  
        }
    }
    if(tmp == to) ans = min(ans, cnt);
}
void solve(){
    // 첫 스위치가 결정되면 나머지가 결정됨 (on/off)
    ans = INF;
    test(true);
    test(false);
    cout << (ans==INF ? -1 : ans);
}
int main(){
    cin >> n >> from >> to;
    solve(); // i번째 스위치 누르면 본인 포함 전/후 전구의 상태가 변함
    return 0;
}