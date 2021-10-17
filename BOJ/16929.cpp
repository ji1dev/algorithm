// 16929번_Two dots
#include <iostream>
#include <stdlib.h>
using namespace std;
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
int n, m, si, sj;
char map[51][51];
bool visited[51][51];
void dfs(int i, int j, int cnt){
    visited[i][j] = true;
    for(int k=0; k<4; ++k){
        int ni = i+di[k];
        int nj = j+dj[k];
        if(ni<0 || ni>=n || nj<0 || nj>=m) continue;
        if(map[i][j] == map[ni][nj]){
            if(!visited[ni][nj]) dfs(ni, nj, cnt+1);
            else{
                // 점 4개 이상을 지나는 사이클이 완성되는 경우
                if(ni==si && nj==sj && cnt>=4){
                    cout << "Yes";
                    exit(0);
                }
            }
        }
    }
    visited[i][j] = false;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(!visited[i][j]){
                si = i; // 사이클 시작 좌표
                sj = j;
                dfs(i, j, 1);
            }
        }
    }
    cout << "No";
    return 0;
}