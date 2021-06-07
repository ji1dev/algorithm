// 1992번_쿼드 트리
#include <iostream>
#include <vector>
using namespace std;
int n, pixel[64][64];
vector<char> ans;
void dc(int xs, int xe, int ys, int ye){
    int current = pixel[xs][ys]; // 현재 분할면의 첫 픽셀
    for(int i=xs; i<xe; ++i){
        for(int j=ys; j<ye; ++j){
            if(pixel[i][j] != current){
                // 현재 분할면에 첫 픽셀과 다른 픽셀이 존재하면
                // 4개 영역으로 분할하고 각각 압축한 뒤 결과를 차례대로 괄호 안에 묶어서 저장
                ans.push_back('(');
                dc(xs, (xs+xe)/2, ys, (ys+ye)/2); // 좌상단
                dc((xs+xe)/2, xe, ys, (ys+ye)/2); // 우상단
                dc(xs, (xs+xe)/2, (ys+ye)/2, ye); // 좌하단
                dc((xs+xe)/2, xe, (ys+ye)/2, ye); // 우하단
                ans.push_back(')');
                return;
            }
        }
        
    }
    // 현재 분할면의 모든 픽셀이 같으면 압축 결과에 해당 픽셀 값을 추가
    ans.push_back(current+'0');
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            scanf("%1d", &pixel[j][i]);
        }
    }
    dc(0, n, 0, n);
    for(int i=0; i<ans.size(); ++i) cout << ans[i];   
    return 0;
}