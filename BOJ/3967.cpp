// 3967번_매직 스타
#include <iostream>
#include <vector>
#include <stdlib.h>
#define MP make_pair
#define F_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// 문제에서 숫자를 확인하는 순서
int oi[][4] = {{0, 1, 2, 3}, {3, 3, 3, 3}, {3, 2, 1, 0}, {1, 2, 3, 4}, {4, 3, 2, 1}, {1, 1, 1, 1}};
int oj[][4] = {{4, 3, 2, 1}, {1, 3, 5, 7}, {7, 6, 5, 4}, {1, 2, 3, 4}, {4, 5, 6, 7}, {7, 5, 3, 1}};
char star[5][9];
bool used[12]; // 12개 알파벳 사용 여부
vector< pair<int, int> > v; // 수가 채워져 있지 않은 곳 좌표
bool check(){
    for(int i=0; i<6; ++i){
        int sum = 0;
        for(int j=0; j<4; ++j){
            sum += star[oi[i][j]][oj[i][j]]-'A'+1; // 현재 줄의 숫자 합 계산
        }
        if(sum != 26) return false;
    }
    return true;
}
void mkStar(int cnt){
    if(cnt == v.size()){ // 빈 칸 모두 채워지면 모든 줄의 숫자 합이 26을 만족하는지 확인
        if(check()){
            for(int i=0; i<5; ++i){
                for(int j=0; j<9; ++j){
                    cout << star[i][j];
                }
                cout << "\n";
            }
            exit(0);
        }
        return;
    }
    for(int i=0; i<12; ++i){ // 12개 알파벳 대입
        if(!used[i]){
            used[i] = true;
            star[v[cnt].first][v[cnt].second] = i+'A'; // 빈 칸을 알파벳으로 채움
            mkStar(cnt+1);
            used[i] = false;
        }
    }
}
int main(){
    F_IO;
    for(int i=0; i<5; ++i){
        for(int j=0; j<9; ++j){
            cin >> star[i][j];
            if(star[i][j]>='A' && star[i][j]<='L') used[star[i][j]-'A'] = true;
            if(star[i][j] == 'x') v.push_back(MP(i, j));
        }
    }
    mkStar(0);
    return 0;
}