// 1697번_숨바꼭질
#include <iostream>
#include <queue>
#include <memory.h>
#define MAX 100001
using namespace std;
int n, k;
queue<int> q;
int visited[MAX];
int main(){
    memset(visited, -1, sizeof(visited));
    cin >> n >> k;
    visited[n] = 0;
    q.push(n);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x == k) break; // 동생 위치 도달
        if(x-1>=0 && visited[x-1]==-1){ // x-1 칸으로 이동
            q.push(x-1);
            visited[x-1] = visited[x]+1;
        }
        if(x+1<MAX && visited[x+1]==-1){ // x+1 칸으로 이동
            q.push(x+1);
            visited[x+1] = visited[x]+1;
        }
        if(x*2<MAX && visited[x*2]==-1){ // x*2 칸으로 이동
            q.push(x*2);
            visited[x*2] = visited[x]+1;
        }
    }
    cout << visited[k]; // 동생 찾는데 소요된 시간
    return 0;
}