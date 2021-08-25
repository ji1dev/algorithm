// 11559번_Puyo Puyo
#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#define MP make_pair
using namespace std;
int ans, di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
char map[12][6];
bool visited[12][6], isPop; // 터지는 뿌요가 있는지 기록
vector< pair<int, int> > v;
void popPuyo(){
    for(int i=0; i<12; ++i){
        for(int j=0; j<6; ++j){
            if(visited[i][j]) map[i][j] = '.';
        }
    }
}
void dropPuyo(){
    for(int j=0; j<6; ++j){
        int base = 11; // 필드에 뿌요가 깔릴 수 있는 base row
        // 가장 아래 row 부터 거꾸로 확인하며 base가 빈 칸이고 현재 row가 base가 아니면 뿌요를 떨어뜨림
        for(int i=11; i>=0; --i){
            if(map[i][j]!='.' && map[base][j]=='.' && base!=i){
                //printf("col:%d / row:%d -> %d\n", j, i, base);
                map[base][j] = map[i][j];
                map[i][j] = '.';
            }
            if(map[base][j] != '.') base--; // base에 뿌요가 존재하면 base를 한 칸 올림
        }
    }
}
void bfs(int oi, int oj){
    char puyo = map[oi][oj];
    queue< pair<int, int> > q;
    q.push(MP(oi, oj));
    v.push_back(MP(oi, oj));
    visited[oi][oj] = true;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0; k<4; ++k){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni<0 || ni >=12 || nj<0 || nj>=6 || visited[ni][nj]) continue;
            if(map[ni][nj] == puyo){ // 기준 뿌요와 같은 뿌요만 그룹에 포함시킴
                q.push(MP(ni, nj));
                v.push_back(MP(ni, nj));
                visited[ni][nj] = true;
            }
        }
    }
}
int main(){
    for(int i=0; i<12; ++i){
        for(int j=0; j<6; ++j){
            scanf("%1s", &map[i][j]);
        }
    }
    while(1){
        isPop = false;
        memset(visited, false, sizeof(visited));
        for(int i=0; i<12; ++i){
            for(int j=0; j<6; ++j){
                if(!visited[i][j] && map[i][j]!='.') bfs(i, j);  
                if(v.size() >= 4){
                    isPop = true;
                }
                else{ // 현재 뿌요 그룹의 뿌요 개수가 4개 미만이면 방문여부 초기화
                    for(int k=0; k<v.size(); ++k){
                        visited[v[k].first][v[k].second] = false;
                    }
                }
                v.clear(); // 확인한 뿌요 그룹 초기화
            }
        }
        if(isPop){
            popPuyo(); // 뿌요 터짐
            dropPuyo(); // 뿌요 떨어짐
            // cout << "After puyo pop\n";
            // for(int i=0; i<12; ++i){
            //     for(int j=0; j<6; ++j){
            //         printf("%c", map[i][j]);
            //     }
            //     printf("\n");
            // }
            ans++; // 같은 턴에서 여러 뿌요 그룹이 터지더라도 연쇄 count는 한번만 증가
        }
        else break; // 더 이상 터질 뿌요 그룹이 없으면 탈출
    }
    cout << ans;    
    return 0;
}