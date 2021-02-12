// 3085번_사탕 게임
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int maxCandy = 0;
char candy[50][50];

void search(){
    // 행 검사
    int cnt, currentMax = 1;
    for(int i=0; i<n; ++i){
        cnt = 1;
        for(int j=0; j<n-1; ++j){
            if(candy[i][j] == candy[i][j+1]) cnt++;
            else{
                // 연속 부분이 끊어진 경우 현재까지의 최대개수를 기록하고 cnt 초기화
                currentMax = max(currentMax, cnt);
                cnt = 1;
            }
        }
        // 한 줄 확인 후 currentMax 갱신
        currentMax = max(currentMax, cnt);
    }

    // 열 검사
    for(int i=0; i<n; ++i){
        cnt = 1;
        for(int j=0; j<n-1; ++j){
            if(candy[j][i] == candy[j+1][i]) cnt++;
            else{
                currentMax = max(currentMax, cnt);
                cnt = 1;
            }
            currentMax = max(currentMax, cnt);
        }
        // 최대 연속 부분의 사탕 개수 갱신
        maxCandy = max(maxCandy, currentMax);
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> candy[i][j];
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n-1; ++j){
            
            // 같은 행의 사탕 교환
            swap(candy[i][j], candy[i][j+1]); 
            search();
            swap(candy[i][j], candy[i][j+1]);

            // 같은 열의 사탕 교환
            swap(candy[j][i], candy[j+1][i]);
            search();
            swap(candy[j][i], candy[j+1][i]);
        }
    }
    cout << maxCandy << "\n";
    return 0;
}