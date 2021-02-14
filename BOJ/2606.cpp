// 2606번_바이러스
#include <iostream>
using namespace std;

bool conn[101][101] = {0, };
bool visit[101] = {0, };
int n, p, x, y, cnt = 0;

void Infected(int com){
    if(!visit[com]){
        visit[com] = true;
        cnt++;
        for(int i=1; i<=n; ++i){
            if(conn[com][i]){
                Infected(i);
            }
        }        
    }
}

int main(){
    cin >> n >> p;
    for(int i=0; i<p; ++i){
        cin >> x >> y;
        conn[x][y] = true;
        conn[y][x] = true;
    }
    Infected(1);
    cout << cnt-1 << "\n";
    return 0;
}