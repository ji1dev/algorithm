// 18405번_경쟁적 전염
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MT make_tuple
#define MAX 201
using namespace std;
int n, k, s, ei, ej, map[MAX][MAX];
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
bool visited[MAX][MAX];
vector<tuple<int, int, int> > v;
queue<tuple<int, int, int> > q;
void solve(){
    for(int k=0; k<v.size(); ++k){
        int a, i, j; // a = 바이러스 번호
        tie(a, i, j) = v[k];
        visited[i][j] = true;
        q.push(v[k]); // 정렬된 바이러스 번호순으로 큐에 들어가므로 자연스럽게 번호가 낮은 바이러스부터 먼저 증식
    }
    while(!q.empty() && s--){ // s초 뒤 결과
        int qs = q.size();
        while(qs--){ // 현 시점에 퍼지는 바이러스들
            int a, i, j;
            tie(a, i, j) = q.front();
            q.pop();
            for(int k=0; k<4; ++k){
                int ni = i+di[k];
                int nj = j+dj[k];
                if(ni<0 || ni>=n || nj<0 || nj>=n || visited[ni][nj]) continue;
                visited[ni][nj] = true;
                map[ni][nj] = a;
                q.push(MT(a, ni, nj));
            }
        }
    }
    cout << map[ei-1][ej-1];
}
int main(){
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> map[i][j];
            if(map[i][j]){
                v.push_back(MT(map[i][j], i, j));
            }
        }
    }
    cin >> s >> ei >> ej;
    sort(v.begin(), v.end()); // 바이러스 번호순으로 정렬
    solve();
    return 0;
}
