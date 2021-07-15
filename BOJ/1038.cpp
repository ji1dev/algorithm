// 1038번_감소하는 수
#include <iostream>
#include <queue>
using namespace std;
int n, order;
queue<long long> q;
void findNum(){
    // 9번째 감소하는 수 까지는 바로 출력 (순서는 0부터 시작)
    if(n <= 9){
        cout << n;
        return;
    }
    // 9번째 감소하는 수 이후를 구하기 위해 1~9까지 큐에 push한 뒤 하나씩 꺼내서 사용함
    for(int i=1; i<=9; ++i) q.push(i);
    order = 9; // 9번째 감소하는 수 까지 확인
    while(!q.empty()){
        long long num = q.front();
        q.pop();
        // 새로운 감소하는 수의 마지막 자리는 현재 감소하는 수의 마지막 자리보다 작은 수만 가능함
        // 따라서 현재 마지막 자리를 십의 자리로 올리고 위 조건을 만족하는 새로운 마지막 자리를 더해줌
        int last = num%10;
        for(int i=0; i<last; ++i){
            // n번째 감소하는 수를 찾은 경우
            if(++order == n){ 
                cout << num*10+i;
                return;
            }
            q.push(num*10+i); // 새로운 감소하는 수 큐에 push
        }
    }
    cout << -1; // n번째 감소하는 수가 없는 경우
}
int main(){
    cin >> n;
    findNum();
    return 0;
}