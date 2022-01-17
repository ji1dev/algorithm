// 15684번_사다리 조작
// 9% 에서 TLE: 매번 가로선 번호를 처음부터 확인하면 중복 발생하기 때문 (line 27)
// 70% 에서 WA: 같은 가로선 번호가 다른 세로선끼리 연결할 때 사용될 수 있음 (line 31)
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, m, h, ans;
bool h_line[11][31]; // 가로선 정보
bool verify(){ // i번 세로선의 결과가 i번이 나오는지 검증
    for(int i=1; i<=n; ++i){
        int v_idx = i;
        for(int j=1; j<=h; ++j){
            if(h_line[v_idx][j]) v_idx++; // 오른쪽 세로선으로 넘어감
            else if(h_line[v_idx-1][j]) v_idx--; // 왼쪽 세로선으로 넘어감
        }
        if(v_idx != i) return false;
    }
    return true;
}
void solve(int h_idx, int v_idx, int cnt){
    if(cnt>3 || cnt>=ans) return; // 추가되는 가로선 3개 초과 or 최솟값 이상인 경우
    if(verify()){
        ans = min(ans, cnt);
        return;
    }
    for(int j=h_idx; j<=h; ++j){ // 가로선 번호 (1~h)
        for(int i=1; i<n; ++i){ // 세로선 번호 (1~n-1)
            if(h_line[i][j] || h_line[i+1][j] || h_line[i-1][j]) continue;
            h_line[i][j] = true;
            solve(j, i, cnt+1); // 세로선 idx도 함께 넘겨줌
            h_line[i][j] = false;
        }
    }

}
int main(){
    cin >> n >> m >> h;
    for(int i=0, a, b; i<m; ++i){
        cin >> a >> b;
        h_line[b][a] = true; // 세로선 b와 b+1을 a위치에서 가로선으로 연결 
    }
    ans = INF;
    solve(1, 1, 0);
    cout << (ans!=INF ? ans : -1);
    return 0;
}