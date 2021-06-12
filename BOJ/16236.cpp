// 16236번_아기 상어
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
struct FishPos{
    int x, y, d;
    FishPos(int x, int y, int d): x(x), y(y), d(d){}; // 구조체 생성자
    // overloading greater than operator to build min heap
    bool operator < (const FishPos &pos) const{
        // 거리가 같으면 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면 가장 왼쪽에 있는 물고기 선택
        if(d == pos.d){ 
            if(x == pos.x) return y > pos.y; // x좌표 같으면 y좌표 가장 작은 값 (가장 위쪽)
            else return x > pos.x; // y좌표 같으면 x좌표 가장 작은 값 (가장 왼쪽)
        }
        else return d > pos.d;
    }
};

int n, ans, shark_size, shark_eat, map[20][20];
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
bool visited[20][20];
priority_queue<FishPos> pq;

void bfs(){
    while(!pq.empty()){
        int cur_x = pq.top().x;
        int cur_y = pq.top().y;
        int cur_d = pq.top().d;
        pq.pop();
        
        // 물고기가 존재하고, 현재 위치의 물고기가 상어 크기보다 작은 경우 해당 칸의 물고기를 먹고 빈 칸으로 만듦
        if(map[cur_x][cur_y]>0 && map[cur_x][cur_y]<shark_size){
            shark_eat++;
            map[cur_x][cur_y] = 0;
            ans += cur_d; // 현재 위치까지의 거리를 더함

            // 먹은 물고기 수가 상어 크기와 같아지면 상어의 크기 증가시키고 그동안 먹은 물고기 수 초기화
            if(shark_eat == shark_size){
                shark_size++;
                shark_eat = 0; 
            }

            // 현재 위치부터 다시 탐색하기 위해 먹은 물고기 수, 거리, 방문기록, 큐 초기화
            cur_d = 0; 
            memset(visited, false, sizeof(visited));
            while(!pq.empty()) pq.pop();
        }

        for(int i=0; i<4; ++i){
            int new_x = cur_x+dx[i];
            int new_y = cur_y+dy[i];

            // 새 좌표가 map범위 내에 들어오고
            if(new_x>=0 && new_x<n && new_y>=0 && new_y<n){
                // 새 좌표의 물고기가 상어보다 작거나 같고, 아직 방문하지 않았다면 지나갈 수 있음 (큐에 push)
                if(map[new_x][new_y]<=shark_size && !visited[new_x][new_y]){
                    visited[new_x][new_y] = true;
                    pq.push(FishPos(new_x, new_y, cur_d+1)); // distance 는 한 칸씩 증가함
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> map[i][j];
            if(map[i][j] == 9){
                map[i][j] = 0;
                shark_size = 2;
                pq.push(FishPos(i, j, 0)); // x, y, 거리
            }
        }
    }
    bfs();
    cout << ans;
    return 0;
}