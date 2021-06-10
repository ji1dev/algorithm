// 9019번_DSLR
#include <iostream>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
bool visited[10000];
void bfs(int a, int b){
    queue< pair<int, string> > q; // 레지스터의 값과 사용한 명령을 pair로 저장
    q.push(make_pair(a, ""));
    visited[a] = true;
    while(!q.empty()){
        int new_n;
        int n = q.front().first;
        string cmd = q.front().second;
        q.pop();
        if(n == b){ // 최종 값에 도달한 경우 출력 후 함수 탈출
            cout << cmd << "\n";
            return;
        }
        new_n = (n*2)%10000; // D명령
        if(!visited[new_n]){ 
            q.push(make_pair(new_n, cmd+"D"));
            visited[new_n] = true;
        }
        new_n = (n==0)?9999:(n-1); // S명령
        if(!visited[new_n]){ 
            q.push(make_pair(new_n, cmd+"S"));
            visited[new_n] = true;
        }
        new_n = (n%1000)*10+(n/1000); // L명령
        if(!visited[new_n]){ 
            q.push(make_pair(new_n, cmd+"L"));
            visited[new_n] = true;
        }
        new_n = (n%10)*1000+(n/10); // R명령
        if(!visited[new_n]){ 
            q.push(make_pair(new_n, cmd+"R"));
            visited[new_n] = true;
        }
    }
}
int main(){
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b; // 레지스터 초기값, 최종값
        memset(visited, false, sizeof(visited));
        bfs(a, b);
    }
    return 0;
}