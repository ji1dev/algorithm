// 11758번_CCW
#include <iostream>
using namespace std;
struct Pos{
    int x, y;
};
int CCW(Pos a, Pos b, Pos c){
    // 벡터 ab와 bc의 외적의 결과에 따라 방향을 알 수 있음
    // 이 때 2차원 평면의 좌표들이므로 z축 성분은 0이고 따라서 아래와 같은 식이 성립함
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int main(){
    struct Pos p[3];
    for(int i=0; i<3; ++i) cin >> p[i].x >> p[i].y;
    int ans = CCW(p[0], p[1], p[2]);
    if(ans > 0) cout << 1; // 반시계
    else if(ans < 0) cout << -1; // 시계
    else cout << 0; // 직선
    return 0;
}