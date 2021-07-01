// 2110번_공유기 설치
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, c;
vector<int> pos;
bool check(int distance){
    int cnt = 1, base = pos[0]; // 최소 1개 공유기는 설치 가능
    for(int i=1; i<n; ++i){
        // 두 좌표간 차이가 계산한 거리 이상이면 base를 다음 좌표로 옮기고 설치 cnt++
        if(pos[i]-base >= distance){
            cnt++;
            base = pos[i];
        }
    }
    if(cnt >= c) return true; // c개 이상 공유기를 설치할 수 있으면 거리 늘릴 수 있음
    return false; // c개 이상 설치 못하면 거리 좁혀야 됨
}
int main(){
    // 주어진 문제를 결정 문제로 변형 -> parametric search
    cin >> n >> c;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        pos.push_back(x);
    }
    sort(pos.begin(), pos.end());
    // 최소 거리는1, 최대 거리는 (가장 끝 좌표-첫 좌표)
    int lower = 1, upper = pos[n-1]-pos[0], d;
    while(lower+1 < upper){
        d = (lower+upper)/2;
        // 현재 거리로 c개 이상 공유기 배치 가능한 경우 거리 늘려서 확인
        // c개 이상 배치 불가능하면 거리를 좁혀서 확인
        if(check(d)) lower = d;
        else upper = d;
    }
    cout << lower; // c개 설치 가능한 거리 값 중 가장 작은 값
    return 0;
}