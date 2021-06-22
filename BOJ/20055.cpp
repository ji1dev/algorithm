// 20055번_컨베이어 벨트 위의 로봇
#include <iostream>
#include <deque>
#define MP make_pair
using namespace std;
int n, k, life, zero, step;
deque< pair<int, bool> > belt; // 각 칸의 내구도, 로봇 존재 여부
void process(){
    // 1. 벨트 한 칸 회전, 내리는 위치의 로봇 내림
    belt.push_front(belt.back()); // 맨 뒤 -> 맨 앞으로
    belt.pop_back();
    belt[n-1].second = false; // 내리는 위치 로봇 내림

    // 2. 가장 먼저 올라간 로봇부터(n-2) 가능하면 앞으로 한 칸씩 이동, 벨트 내구도 감소
    for(int i=n-2; i>=0; --i){
        // 현재 칸에 로봇이 있고, 앞 칸 내구도 1이상이며 비어있는 경우
        if(belt[i].second && belt[i+1].first>=1 && !belt[i+1].second){ 
            belt[i+1].first--; // 앞 칸 내구도 감소
            belt[i+1].second = true; // 앞 칸으로 로봇 옮김
            belt[i].second = false;
        }
    }
    belt[n-1].second = false; // 내리는 위치 로봇 내림

    // 3. 올리는 위치의 내구도 0 아니면 로봇 올리고 벨트 내구도 감소
    if(belt[0].first != 0){
        belt[0].first--;
        belt[0].second = true;
    }

    // 4. 내구도 0인 칸 개수 count
    zero = 0;
    for(int i=0; i<n*2; ++i){
        if(belt[i].first == 0) zero++;
    }
}
int main(){
    cin >> n >> k;
    for(int i=0; i<n*2; ++i){
        cin >> life;
        belt.push_back(MP(life, false));
    }
    // 내구도 0인 칸 개수가 k개 미만이면 반복
    while(zero < k){
        process();
        step++;
    }
    cout << step;
    return 0;
}