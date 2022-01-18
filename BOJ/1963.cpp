// 1963번_소수 경로
#include <iostream>
#include <queue>
#include <string>
#include <memory.h>
#define MAX 10001
using namespace std;
int t, visited[MAX];
bool isPrime[MAX];
void bfs(int src, int dst){
    queue<int> q;
    memset(visited, -1, sizeof(visited));
    q.push(src);
    visited[src] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == dst){
            cout << visited[cur] << "\n";
            return;
        }
        for(int i=0; i<4; ++i){ // 각 자리마다 숫자 바꿔가며 확인
            string s = to_string(cur);
            for(int j=0; j<=9; ++j){
                s[i] = j+'0';
                int next = stoi(s);
                if(next<1000 || !isPrime[next]) continue; // 1000미만이거나 소수 아니면 넘어감
                if(visited[next] != -1) continue;
                visited[next] = visited[cur]+1;
                q.push(next);
            }
        }
    }
    cout << "Impossible\n";
}
int main(){
    // Sieve of Eratosthenes
    memset(isPrime, true, sizeof(isPrime));
    for(int i=2; i<MAX; ++i){
        if(isPrime[i]){
            for(int j=i*2; j<MAX; j+=i) isPrime[j] = false;
        }
    }
    cin >> t;
    while(t--){
        int src, dst;
        cin >> src >> dst;
        bfs(src, dst);
    }
    return 0;
}