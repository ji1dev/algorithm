// 12865번_평범한 배낭
#include <iostream>
#include <algorithm>
using namespace std;
int n, k, profit[101][100001], item[101][2];
int main(){
    cin >> n >> k; // 물건의 수, 버틸 수 있는 무게
    for(int i=1; i<=n; ++i){
        cin >> item[i][0] >> item[i][1]; // weight, value
    }
    for(int i=1; i<=n; ++i){
        int weight = item[i][0];
        int value = item[i][1];
        for(int w=0; w<=k; ++w){
            // 전체 무게가 w를 넘지 않도록 i번째까지의 물건을 담았을 때 최대 이익을 DP로 구함
            // 현재 물건 무게 w이하 -> 포함 or 미포함 중 더 큰 쪽을 선택 (가치 갱신 or 이전 가치 그대로)
            // 현재 물건 무게 w초과 -> 미포함 (이전 물건까지의 가치를 그대로 사용)
            if(item[i][0] <= w)
                profit[i][w] = max(profit[i-1][w], profit[i-1][w-weight]+value);
            else
                profit[i][w] = profit[i-1][w];
        }
    }
    cout << profit[n][k];
    return 0;
}