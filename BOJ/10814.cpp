// 10814번_나이순 정렬
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(pair<int, string> a, pair<int, string> b){
    // pair 의 첫 인자만 비교함
    return a.first < b.first;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int, string> > info(n);
    for(int i=0; i<n; ++i){
        cin >> info[i].first >> info[i].second;
    }
    // 사용자 정의 비교함수를 가리키는 포인터 cmp
    // stable_sort 함수는 원소의 순서를 보장함
    // 비교함수에서 첫 인자만 비교하므로 두 번째 인자인 string은 순서가 변하지 않음
    stable_sort(info.begin(), info.end(), cmp);
    for(int i=0; i<n; ++i){
        cout << info[i].first << " " << info[i].second << "\n";
    }
    return 0;
}