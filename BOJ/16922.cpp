// 16922번_로마 숫자 만들기
#include <iostream>
using namespace std;
int n, ans, r[] = {1, 5, 10, 50};
bool visited[1001];
void mkNum(int len, int begin, int sum){
    if(len == n){
        if(!visited[sum]){ // 처음 만들어진 숫자 조합만 더함
            visited[sum] = true;
            ans++;
        }
        return;
    }
    for(int i=begin; i<4; ++i){
        sum += r[i];
        mkNum(len+1, i, sum);
        sum -= r[i];
    }
}
int main(){
    cin >> n;
    mkNum(0, 0, 0);
    cout << ans;
    return 0;
}