// 14719번_빗물
#include <iostream>
#include <algorithm>
using namespace std;
int h, w, block[501];
int lh, rh, limit, water, sum;
void findHighest(int base){
    for(int j=0; j<base; ++j) lh = max(lh, block[j]);
    for(int j=base+1; j<w; ++j) rh = max(rh, block[j]);
}
int main(){
    cin >> h >> w;
    for(int i=0; i<w; ++i) cin >> block[i];
    // 첫 열과 마지막 열에는 물이 고일 수 없으므로 생략
    for(int j=1; j<w-1; ++j){
        if(block[j] == h) continue; // 블록으로 가득 차있어 물이 고일 수 없는 열은 생략
        lh = rh = 0;
        findHighest(j); // 현재 열 기준 왼편, 오른편에서 각각 가장 높은 벽을 구함 
        limit = min(lh, rh); // 둘 중 낮은 벽의 높이가 물이 고일 수 있는 최대치
        water = limit-block[j]; // 현재 열의 벽 높이 제외한만큼 물이 고임
        if(water > 0) sum += water;
    }
    cout << sum;
    return 0;
}