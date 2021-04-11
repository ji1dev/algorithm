// 18111번_마인크래프트
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main(){
    int N, M, B;
    int min_h = 256, max_h = 0, ans_h = 0;
    int elapsed_time = 0, min_time = INT_MAX;
    int land[501][501] = {0, };
    cin >> N >> M >> B;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin >> land[i][j];
            // 가장 높은 블록과 낮은 블록을 구함
            if(land[i][j] < min_h) min_h = land[i][j];
            if(land[i][j] > max_h) max_h = land[i][j];
        }
    }
    for(int h=min_h; h<=max_h; ++h){
        int sum_add = 0, sum_rm = 0;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                int diff = h-land[i][j];
                if(diff < 0){
                    // 확인중인 높이가 현재 블록의 높이보다 낮은 경우 블록을 제거해서 높이를 맞춤
                    sum_rm += -1*diff;
                }
                else{
                    // 확인중인 높이가 현재 블록의 높이보다 높은 경우 블록을 추가해서 높이를 맞춤
                    sum_add += diff;
                }
            }
        }
        if(sum_add <= (sum_rm+B)){
            // 추가할 블록의 수가 (인벤토리의 블록 + 제거한 블록)으로 커버 가능하면 시간을 계산
            elapsed_time = sum_add + (sum_rm*2);
            if(elapsed_time < min_time){
                // 최소 시간 갱신
                min_time = elapsed_time;
                ans_h = h;
            }
            if(elapsed_time == min_time){
                // 땅 고르는 시간이 같으면 땅의 높이가 가장 높은것으로 갱신
                if(ans_h < h) ans_h = h;
            }
        }
    }
    cout << min_time << " " << ans_h;
    return 0;
}