// 2512번_예산
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, sum;
vector<int> v;
bool check(int mid){
    int s = 0;
    for(int i=0; i<v.size(); ++i){
        if(v[i] <= mid) s += v[i];
        else s += mid; // 상한액보다 예산이 크면 상한액으로 계산
    }
    if(s <= m) return true; // 예산총액보다 합이 작으면 배정 성공
    return false; // 예산총액보다 합이 크면 배정 불가
}
int main(){
    cin >> n;
    // 예산 n개 입력
    for(int i=0; i<n; ++i){
        int a;
        cin >> a;
        v.push_back(a);
        sum += v[i];
    }
    cin >> m; // 총 예산
    sort(v.begin(), v.end());
    if(sum <= m) cout << v[n-1];
    else{
        int left = 0;
        int right = v[n-1];
        while(left+1 < right){
            int mid = (left+right)/2;
            // 현재 상한액으로 예산 배정에 성공한 경우
            if(check(mid)) left = mid;
            else right = mid;
        }
        // left는 항상 예산총액을 만족하는 값으로, 
        // while loop를 탈출하는 시점에서는 상한액 중 최댓값이 됨
        cout << left; 
    }
    return 0;
}