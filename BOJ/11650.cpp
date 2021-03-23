// 11650번_좌표 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    // 데이터 쌍을 표현하기 위해 pair 클래스 사용
    // first, second 두 개의 변수 저장 가능
    // sort()사용시 first 기준으로 정렬하고 first가 같으면 second로 판단하여 정렬함
    vector<pair<int, int> >pos(n);
    for(int i=0; i<n; ++i){
        cin >> pos[i].first >> pos[i].second;
    }
    sort(pos.begin(), pos.end());
    for(int i=0; i<n; ++i){
        cout << pos[i].first << " " << pos[i].second << "\n";
    }
    return 0;
}