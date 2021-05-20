// 12851번_숨바꼭질 2
#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
int n, k, ans, cnt;
queue< pair<int, int> > q;
bool visited[MAX];
int main(){
    cin >> n >> k;
    visited[n] = true;
    q.push(make_pair(n, 0));
    while(!q.empty()){
        int x = q.front().first; // 현재 수빈이의 위치
        int sec = q.front().second; // 소요 시간
        q.pop();
        visited[x] = true;

        // 이미 동생을 찾은 뒤 더 찾고있는 상황에서 
        // 현재 위치까지 도달하는 시간이 가장 빠른 소요 시간보다 크면 더 볼 필요 없음
        if(ans!=0 && ans<sec) break;

        if(x == k){
            // 동생 위치 도달하면 cnt증가
            if(!ans) ans = sec; // 처음 찾은 경우 ans 갱신
            cnt++;
        }

        if(x-1>=0 && !visited[x-1]){ // x-1 칸으로 이동
            q.push(make_pair(x-1, sec+1));
        }
        if(x+1<MAX && !visited[x+1]){ // x+1 칸으로 이동
            q.push(make_pair(x+1, sec+1));
        }
        if(x*2<MAX && !visited[x*2]){ // x*2 칸으로 이동
            q.push(make_pair(x*2, sec+1));
        }
    }
    
    // 동생을 찾는 가장 빠른 시간과 해당 시간으로 찾는 방법의 수
    cout << ans << "\n" << cnt;
    return 0;
}