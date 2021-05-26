// 11729번_하노이 탑 이동 순서
#include <iostream>
#include <vector>
using namespace std;
vector < pair<int, int> > mv;

void hanoi(int from, int pass, int to, int n){
    // pass는 거쳐가는 장대
    // 벡터에 push
    if(n == 1) mv.push_back(make_pair(from, to)); // 한개의 원판을 옮겼음을 기록
    else{
        hanoi(from, to, pass, n-1); // n-1개 원판을 3번을 거쳐 2번으로 옮김
        mv.push_back(make_pair(from, to)); // 한개의 원판을 옮겼음을 기록
        hanoi(pass, from, to, n-1); // n-1개 원판을 1번을 거쳐 3번으로 옮김
    }
}
int main(){
    int n;
    cin >> n;
    hanoi(1, 2, 3, n); // n개 원판을 1번 장대에서 3번 장대로 옮김
    cout << mv.size() << "\n"; // 원판을 이동한 횟수
    for(int i=0; i<mv.size(); ++i){
        cout << mv[i].first << " " << mv[i].second << "\n";
    }
    return 0;
}