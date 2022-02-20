// 2422번_한윤정이 이탈리아에 가서 아이스크림을 사먹는데
#include <iostream>
#define MAX 201
using namespace std;
int n, m;
bool check[MAX][MAX];
void solve(){
    int cnt = 0;
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            if(check[i][j]) continue; // 2개 선택 후 확인
            for(int k=j+1; k<=n; ++k){
                if(check[i][k] || check[j][k]) continue; // 3개 선택 후 확인
                cnt++;
            }
        }
    }
    cout << cnt;    
}
int main(){
    cin >> n >> m;
    for(int i=0, a, b; i<m; ++i){
        cin >> a >> b; // 섞어먹으면 안 되는 조합
        check[a][b] = check[b][a] = true;
    }
    solve();
    return 0;
}