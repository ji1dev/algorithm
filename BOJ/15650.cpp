// 15650번_N과 M (2)
// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
// 고른 수열은 오름차순
#include <iostream>
using namespace std;
int n, m, arr[9];
bool visit[9];
void MakeSequence(int num){
    if(num == m){ // 길이가 m인 수열이 생성되면 출력 후 탈출
        for(int i=0; i<m; ++i){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    // 1 ~ N의 자연수 중 아직 고르지 않았고 
    // 수열의 앞 자리 수보다 큰 숫자를 수열에 추가함
    for(int i=1; i<=n; ++i){
        if(!visit[i]){ 
            if(arr[num-1] < i){
                arr[num] = i;
                visit[i] = true; // 숫자 i 방문 처리
                MakeSequence(num+1); // 다음 depth로 넘어가기
                visit[i] = false; // 숫자 i 방문 해제
            }
        }
    }
}
int main(){
    cin >> n >> m;
    MakeSequence(0);
    return 0;
}