// 2346번_풍선 터뜨리기
#include <iostream>
#include <deque>
#include <algorithm>
#define MP make_pair
using namespace std;
int n;
deque<pair<int, int> > dq;
int main(){
    cin >> n;
	for(int i=0; i<n; ++i){
		int val;
		cin >> val;
        dq.push_back(MP(i+1, val));
	}
    // 제일 처음에는 1번 풍선을 터뜨림
    cout << dq.front().first << " ";
    int tmp = dq.front().second;
	dq.pop_front();
	while(!dq.empty()){
        // 적혀있는 수가 양수면 오른쪽, 음수면 왼쯕으로 이동
		if(tmp > 0){
			for(int i=0; i<tmp; ++i) {
				dq.push_back(MP(dq.front().first, dq.front().second));
				dq.pop_front();
			}
            cout << dq.back().first << " ";
            tmp = dq.back().second;
			dq.pop_back();
		}
		else{
			for(int i=0; i<abs(tmp); ++i){
				dq.push_front(MP(dq.back().first, dq.back().second));
				dq.pop_back();
			}
            cout << dq.front().first << " ";
			tmp = dq.front().second;
			dq.pop_front();
		}
	}
	return 0;
}