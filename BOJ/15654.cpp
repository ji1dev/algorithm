// 15654번_N과 M (5)
// N 자연수 중에서 M개를 고른 수열
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[8], ans[8];
bool visit[8];
void MakeSequence(int num){
    if(num == m){ // 길이가 m인 수열이 생성되면 출력 후 탈출
        for(int i=0; i<m; ++i){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    // 정렬된 N개 자연수 중 고르지 않은 숫자를 수열에 추가함
    for(int i=0; i<n; ++i){
        if(!visit[i]){   
            ans[num] = arr[i];
            visit[i] = true; // 숫자 i 방문 처리
            MakeSequence(num+1); // 다음 depth로 넘어가기
            visit[i] = false; // 숫자 i 방문 해제
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    sort(arr, arr+n);
    MakeSequence(0);
    return 0;
}