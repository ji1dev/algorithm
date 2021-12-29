// 1347번_미로 만들기
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, mxi, mxj, mni, mnj;
int dir, di[] = {1, 0, -1, 0}, dj[] = {0, -1, 0, 1}; // 남쪽부터 시계방향
char map[101][101];
string s;
int main(){
    cin >> n >> s;
    for(int i=0; i<101; ++i){
        for(int j=0; j<101; ++j){
            map[i][j] = '#';
        }
    }
    int i = 50, j = 50; // 위치
    mxi = mxj = mni = mnj = 50; // map 표시 범위
    map[i][j] = '.'; // 초기 위치
    for(int k=0; k<s.length(); ++k){
        if(s[k] == 'R') dir = (dir+1)>3 ? 0 : dir+1;
        else if(s[k] == 'L') dir = dir-1<0 ? 3 : dir-1;
        else{ // 이동
            i += di[dir];
            j += dj[dir];
            map[i][j] = '.'; // 이동할 수 있는 칸
        }
        mxi = max(mxi, i);
        mxj = max(mxj, j);
        mni = min(mni, i);
        mnj = min(mnj, j);
    }
    for(int i=mni; i<=mxi; ++i){
        for(int j=mnj; j<=mxj; ++j){
            cout << map[i][j];
        }
        cout << "\n";
    }
    return 0;
}