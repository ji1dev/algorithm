// 9207번_페그 솔리테어
#include <iostream>
#include <algorithm>
using namespace std;
char map[5][9];
int n, pins, removed, di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
void dfs(int rm){
    for(int i=0; i<5; ++i){
        for(int j=0; j<9; ++j){
            if(map[i][j] == 'o'){
                for(int k=0; k<4; ++k){
                    int ni = i+di[k]; // 인접 칸
                    int nj = j+dj[k];
                    if(ni<0 || ni>=5 || nj<0 || nj>=9) continue;
                    if(map[ni][nj] != 'o') continue;

                    int nni = ni+di[k]; // 인접 칸의 다음 칸
                    int nnj = nj+dj[k];
                    if(nni<0 || nni>=5 || nnj<0 || nnj>=9) continue;
                    if(map[nni][nnj] != '.') continue;

                    map[i][j] = map[ni][nj] = '.'; // 핀 넘기고 인접 핀 제거
                    map[nni][nnj] = 'o';
                    dfs(rm+1); // 제거한 핀 개수 ++
                    map[i][j] = map[ni][nj] = 'o'; // 되돌림
                    map[nni][nnj] = '.';
                }
            }
        }
    }
    // 핀을 움직여서 남길 수 있는 핀의 최소 개수를 구하기 위해 제거되는 핀의 최댓값을 갱신
    removed = max(removed, rm);
}
int main(){
    cin >> n;
    while(n--){
        removed = pins = 0;
        for(int i=0; i<5; ++i){
            for(int j=0; j<9; ++j){
                scanf("%1s", &map[i][j]);
                if(map[i][j] == 'o') pins++;
            }
        }
        dfs(0);
        // 인접 핀이 있을때만 이동 가능하므로 제거한 핀의 개수는 이동 횟수와 같음
        cout << pins-removed << " " << removed << "\n";
        
    }
    return 0;
}