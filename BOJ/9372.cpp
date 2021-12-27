// 9372번_상근이의 여행
#include <iostream>
using namespace std;
int t;
// 1. 입력으로 주어지는 비행 스케줄은 항상 연결 그래프를 이룸 (모든 정점 연결됨)
// 2. 모든 간선의 가중치가 1임
// 따라서 모든 국가 방문을 위한 최소 탑승 비행기 개수는 정점 N개인 MST의 간선 개수와 동일 (N-1개)
int main(){
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=0; i<m; ++i){
            int a, b;
            cin >> a >> b;
        }
        cout << n-1 << "\n";
    }
    return 0;
}