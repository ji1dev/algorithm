// 18870번_좌표 압축
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, tmp;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        v.push_back(tmp);
    }
    vector<int> v2(v);
    sort(v2.begin(), v2.end());
    // unique는 vector의 구간 내 중복되지 않는 원소들만 앞에서부터 채우고 
    // 변경된 vector의 end()를 리턴함
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    for(int i=0; i<n; ++i){
        // lower_bound는 iterator를 리턴하므로 vector시작 주소를 빼줘서 idx를 구함
        cout << lower_bound(v2.begin(), v2.end(), v[i])-v2.begin() << " ";
    }
    return 0;
}