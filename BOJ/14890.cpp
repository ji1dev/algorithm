// 14890번_경사로
#include <iostream>
using namespace std;
int n, L, map[101][101], tmap[101][101];
int buildRoad(int m[][101]){
    int roads = 0;
    for(int i=0; i<n; ++i){
        int diff, visit = 1; // 높이 같은 칸 개수
        bool isOK = true;
        for(int j=0; j<n-1; ++j){
            diff = m[i][j]-m[i][j+1];
            if(diff == 0){ // 높이 같으면 길 이어갈 수 있음
                visit++;
            }
            else if(diff == -1){ // 뒤가 한칸 더 높음 (오르막 경사로 필요)
                if(visit < L){
                    isOK = false;
                    break;
                }
                else{ // 오르막 경사로 설치할 수 있는 칸이 충분한 경우
                    visit = 1; // 높이 같은 칸 개수 초기화
                }
            }
            else if(diff == 1){ // 앞이 한칸 더 높음 (내리막 경사로 필요)
                int next = 0, base = m[i][j+1];
                for(int k=j+1; k<=j+L; ++k){ // 경사로 설치할 칸이 충분한지 확인
                    if(base == m[i][k]) next++;
                }
                if(next != L){
                    isOK = false;
                    break;
                }
                else{ // 내리막 경사로 설치할 수 있는 칸이 충분한 경우
                    j += (L-1); // 경사로가 끝나는 곳 직전 칸으로 이동 (++j하면 끝나는 칸으로 감)
                    visit = 0; // 경사로가 끝나는곳의 높이는 그 다음칸과 같지 않음 (경사로 겹치는 상황 방지)
                }
            }
            else{ // 길을 만들 수 없음
                isOK = false;
                break;
            }
        }
        if(isOK) roads++; // 길 완성
    }
    return roads;
}
int main(){
    cin >> n >> L;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> map[i][j];
            tmap[j][i] = map[i][j]; // transposed matrix
        }
    }
    cout << buildRoad(map)+buildRoad(tmap);
    return 0;
}