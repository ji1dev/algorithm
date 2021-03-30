// 10989번_수 정렬하기 3
#include <iostream>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    F_I;
    int n, num, arr[10001] = {0, };
    cin >> n;
    // 입력 숫자별 개수를 count하고 해당 숫자의 개수만큼 출력
    for(int i=1; i<=n; ++i){
        cin >> num;
        arr[num]++;
    }
    for(int i=1; i<=10000; ++i){
        for(int j=0; j<arr[i]; ++j){
            cout << i << "\n";
        }
    }
    return 0;
}