// 8911번_거북이
#include <iostream>
#include <algorithm>
#include <string>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int t, di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1}; // top, right, bottom, left
int main(){
    F_IO;
    cin >> t;
    while(t--){
        string cmd;
        cin >> cmd;
        int i = 0, j = 0, min_i = 0, min_j = 0, max_i = 0, max_j = 0, way = 0; // 시작 방향은 북쪽 
        for(int k=0; k<cmd.length(); ++k){
            if(cmd[k] == 'L') way = (way-1)>=0 ? way-1 : 3; // 방향 전환
            else if(cmd[k] == 'R') way = (way+1)<=3 ? way+1 : 0;
            else if(cmd[k] == 'F'){ // 한 눈금 이동
                i += di[way];
                j += dj[way];
            }
            else if(cmd[k] == 'B'){
                i -= di[way];
                j -= dj[way];
            }
            min_i = min(min_i, i); // 최대, 최소 좌표 갱신
            min_j = min(min_j, j);
            max_i = max(max_i, i);
            max_j = max(max_j, j);
        }
        cout << (max_i-min_i)*(max_j-min_j) << "\n"; // 거북이가 지난 영역을 포함하는 최소 직사각형 넓이
    }
    return 0;
}