// 1080번_행렬
#include <iostream>
using namespace std;
int cnt, n, m, a[51][51], b[51][51];
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            scanf("%1d", &a[i][j]);
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            scanf("%1d", &b[i][j]);
        }
    }
    for(int i=0; i<n-2; ++i){ // 3x3 부분행렬 만들 수 있는 범위
        for(int j=0; j<m-2; ++j){
            if(a[i][j] != b[i][j]){
                for(int k=i; k<i+3; ++k){ // 3x3 부분행렬 뒤집기
                    for(int l=j; l<j+3; ++l){
                        a[k][l] = 1-a[k][l];
                    }
                }
                cnt++;
            }
            else continue;
        }
    }
    bool flag = true;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(a[i][j] != b[i][j]){ // 바뀌지 않은 원소
                flag = false;
                break;
            }
        }
    }
    if(flag) cout << cnt;
    else cout << -1;
    return 0;
}