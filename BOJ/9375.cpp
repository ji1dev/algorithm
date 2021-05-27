// 9375번_패션왕 신해빈
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    int t, n, ans;
    string item, type;
    map<string, int> clothes;
    cin >> t;
    while(t--){
        ans = 1;
        cin >> n;
        for(int i=0; i<n; ++i){
            cin >> item >> type;
            if(clothes.find(type) == clothes.end()){ // map에 type에 해당하는 옷이 존재하지 않는 경우
                clothes.insert(make_pair(type, 1)); // 해당 type에 해당하는 옷 개수 초기값 1로 설정
            }
            else{ // map에 type에 해당하는 옷이 존재하는 경우
                clothes[type]++; // 해당 type에 해당하는 옷 개수 증가
            }
        }
        for(auto iter : clothes){ // map내부를 iterator를 이용해서 순회
            // 이전 의상을 선택하는 경우의 수 * (의상 종류마다 선택할 수 있는 경우의 수 + 선택하지 않는 경우)
            ans *= (iter.second + 1);
        }
        cout << ans-1 << "\n"; // 아무것도 입지 않는 경우는 제외
        clothes.clear();
    }
    return 0;
}