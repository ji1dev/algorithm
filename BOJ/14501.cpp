// 14501번_퇴사
#include <iostream>
#include <algorithm>
using namespace std;
int n, t[16], p[16], endDate, maxProfit = 0;
bool worked[16];
void Work(int day, int profit){
    // i일차에 시작한 상담의 종료일이 퇴사일 이전이고 
    // 해당 날짜에 상담이 잡혀있지 않으면 해당 일자의 수입을 계산
    for(int i=day; i<=n; ++i){ 
        endDate = i+t[i]-1;
        if(endDate < n+1){
            if(!worked[i]){
                worked[i] = true;
                profit += p[i];
                maxProfit = max(maxProfit, profit); // 최대 수입 갱신
                Work(endDate+1, profit); // 다음 상담 날짜로 넘어감
                worked[i] = false; 
                profit -= p[i]; // i일차 수입 빼주기
            }
        }else{
            continue;
        }
    }
}
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> t[i] >> p[i];
    Work(1, 0);
    cout << maxProfit << "\n";
    return 0;
}