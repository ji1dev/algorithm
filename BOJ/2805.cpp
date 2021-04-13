// 2805번_나무 자르기
#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;
int N;
long M, H, MAXH, tree[MAX];
bool Logging(int h){
    long sum = 0;
    for(int i=0; i<N; ++i){
        if(tree[i]-h > 0) sum += tree[i]-h;
    }
    // 목표치 M보다 벌목된 양이 많거나 같은 경우 return true, 아니면 false
    if(sum >= M) return true;
    return false;
}
int main(){
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        cin >> tree[i];
        MAXH = max(MAXH, tree[i]);
    }
    sort(tree, tree+N);
    long left = 0, right = MAXH;
    while(left <= right){
        long mid = (left+right)/2;
        if(Logging(mid)){
            // 현재 높이로 벌목했을 때 목표치보다 양이 많으면 절단기의 높이를 높임
            H = max(H, mid); // 최대 절단기 높이를 갱신
            left = mid+1;
        }else{
            // 현재 높이로 벌목했을 때 목표치보다 양이 적으면 절단기의 높이를 낮춤
            right = mid-1;       
        }
    }
    cout << H;
    return 0;
}