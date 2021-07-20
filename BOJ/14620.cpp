// 14620번_꽃길
#include <iostream>
#include <algorithm>
using namespace std;
int n, min_cost, price[10][10];
int di[] = {0, -1, 1, 0, 0}, dj[] = {0, 0, 0, -1, 1};
bool visited[10][10];
void Visit(int i, int j, bool opt){
    for(int k=0; k<5; ++k){
        visited[i+di[k]][j+dj[k]] = opt; // true or false
    }
}
bool Promising(int i, int j){
    for(int k=0; k<5; ++k){
        if(visited[i+di[k]][j+dj[k]]) return false;
    }
    return true; // 꽃 중심과 꽃잎 4개 모두 겹치지 않으면 true
}
void Flower(int cnt){
    if(cnt == 3){
        int cost = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(visited[i][j]) cost += price[i][j];
            }
        }
        min_cost = min(min_cost, cost);
        return;
    }
    // 꽃의 중심이 가장자리에 있으면 꽃이 필 수 없으므로 가장자리는 범위에서 제외
    for(int i=1; i<n-1; ++i){
        for(int j=1; j<n-1; ++j){
            // 현 위치에서 꽃을 피웠을 때 기존 꽃들과 겹치지 않는지 확인하고 진행
            if(!Promising(i, j)) continue;
            Visit(i, j, true);
            Flower(cnt+1);
            Visit(i, j, false);
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> price[i][j];
        }
    }
    min_cost = 987654321;
    Flower(0);
    cout << min_cost;
    return 0;
}