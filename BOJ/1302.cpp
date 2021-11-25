// 1302번_베스트셀러
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int n, max_cnt;
string s;
map<string, int> m; // key값 기준 오름차순 정렬됨
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> s;
        m[s]++; // 각 책의 개수
        max_cnt = max(max_cnt, m[s]);
    }
    for(auto i : m){
        // 처음 나오는 가장 많이 팔린 책이 사전순으로 앞서는 제목이므로 출력하고 바로 종료
        if(max_cnt == i.second){
            cout << i.first;
            return 0;
        }
    }
    return 0;
}