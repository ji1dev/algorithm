// 16928번_뱀과 사다리 게임
#include <iostream>
#include <queue>
using namespace std;
int jmp[101]; // 사다리, 뱀 정보
int cnt[101]; // 현재 칸에 도착하기 위해 주사위 굴린 횟수
int main(){
    int n, m, x, y, cur, next;
    queue<int> q;
    cin >> n >> m;
    for(int i=0; i<n+m; ++i){
        cin >> x >> y; // 사다리, 뱀 정보 저장
        jmp[x] = y;
    }
    q.push(1);
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(int i=1; i<=6; ++i){ 
            next = cur+i; // 주사위 굴려 1~6만큼 이동한 곳이 다음 칸
            if(next <= 100){
                if(jmp[next] != 0) next = jmp[next]; // 다음 칸에 사다리나 뱀 있으면 타고 넘어감
                if(cnt[next] == 0){
                    // 해당 칸에 처음 방문할 경우에만 cnt갱신하고 큐에 삽입
                    cnt[next] = cnt[cur]+1;
                    q.push(next);
                }
            }
        }
    }
    cout << cnt[100];
    return 0;
}