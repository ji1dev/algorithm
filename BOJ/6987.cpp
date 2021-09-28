// 6987번_월드컵
#include <iostream>
#include <algorithm>
#include <memory.h>
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MP make_pair
using namespace std;
int c1[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4}; // 경기를 치르는 국가 조합
int c2[] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5}; // 0->1,2,3,4,5 / 1->2,3,4,5 ...
int ans, score[6][3], test[6][3]; // 승, 무승부, 패 횟수 기록
void dfs(int cnt){
    if(cnt == 15){ // 15회 경기 모두 끝나면 계산한 결과가 주어진 결과와 같은지 확인 
        for(int i=0; i<6; ++i){
            for(int j=0; j<3; ++j){ // 각 팀의 승, 무, 패 결과 비교
                if(test[i][j] != score[i][j]){
                    return;
                }
            }
        }
        ans = 1; // 모든 결과 같으면 가능한 결과로 저장
        return;
    }
    // 경기 치르는 국가 조합으로 승-패, 무-무, 패-승 경우를 테스트
    test[c1[cnt]][0]++; // 승리 횟수
    test[c2[cnt]][2]++; // 패배 횟수
    dfs(cnt+1);
    test[c1[cnt]][0]--;
    test[c2[cnt]][2]--;

    test[c1[cnt]][1]++; // 무승부 횟수
    test[c2[cnt]][1]++;
    dfs(cnt+1);
    test[c1[cnt]][1]--;
    test[c2[cnt]][1]--;

    test[c1[cnt]][2]++;
    test[c2[cnt]][0]++;
    dfs(cnt+1);
    test[c1[cnt]][2]--;
    test[c2[cnt]][0]--;
}

int main() {
    F_IO;
    // 6개국가 승, 무승부, 패 결과 입력
    for(int t=0; t<4; ++t){
        memset(test, 0, sizeof(test));
        ans = 0;
        for(int i=0; i<6; ++i){
            for(int j=0; j<3; ++j){
                cin >> score[i][j];
            }
        }
        dfs(0);
        cout << ans << " ";
    }
    return 0;
}