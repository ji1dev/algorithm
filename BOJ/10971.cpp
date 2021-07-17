// 10971번_외판원 순회 2
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int n, w[10][10], min_cost = INF;
bool visited[10];
vector<int> path;
void travel(int len){
    // n개 도시를 방문하는 경로의 후보지가 완성된 경우
    if(len == n){
        int cost = 0;
        // 첫 도시 ~ 마지막 도시까지 각각 실제 간선이 존재하는지 확인
        // 존재한다면 해당 간선의 비용을 더함
        for(int i=1; i<n; ++i){
            if(w[path[i-1]][path[i]]) cost += w[path[i-1]][path[i]];
            else return;
        }
        // 마지막 도시 -> 첫 도시로 돌아오는 간선이 존재한다면 해당 간선의 비용을 더함
        // 모든 도시를 순회하는 최소 비용을 갱신함
        if(w[path[n-1]][path[0]]){
            cost += w[path[n-1]][path[0]];
            min_cost = min(min_cost, cost);
        }
        return;
    }
    for(int i=0; i<n; ++i){
        if(!visited[i]){
            path.push_back(i); // 경로 후보에 추가
            visited[i] = true;
            travel(len+1);
            path.pop_back();
            visited[i] = false;
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> w[i][j];
        }
    }
    travel(0);
    cout << min_cost;
    return 0;
}