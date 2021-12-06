// 13414번_수강신청
#include <iostream>
#include <algorithm>
#include <map>
#define MP make_pair
using namespace std;
int k, l, cnt, id[500005];
map<int, int> m;
int main(){
    cin >> k >> l;
    for(int i=0; i<l; ++i){
        cin >> id[i];
        m[id[i]] = i; // 학번을 key로 저장
    }
    for(int i=0; i<l; ++i){
        // value는 입력 순서대로이므로 i번째로 들어온 학생이 저장된 value와 같은지 확인
        // k명 모두 신청되면 탈출함
        if(cnt >= k) break;
        if(m[id[i]] == i){
            printf("%08d\n", id[i]);
            cnt++;
        }
    }
    return 0;
}