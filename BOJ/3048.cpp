// 3048번_개미
#include <iostream>
#define MP make_pair
using namespace std;
int n1, n2, t;
char ant;
pair<char, int> seq[26], tmp;
int main(){
    /*
    0: CBA DEF
    1: CBD AEF
    2: CDB EAF
    */
    cin >> n1 >> n2;
    for(int i=0; i<n1+n2; ++i){
        cin >> ant;
        if(i<n1) seq[n1-i-1] = MP(ant, 1); // 오른쪽으로 이동하는 개미
        else seq[i] = MP(ant, 0); // 왼쪽으로 이동하는 개미
    }
    cin >> t;
    while(t--){
        for(int i=1; i<n1+n2; ++i){
            // 방향 다르면 오른쪽 이동 개미 기준으로 swap
            if(seq[i-1].second != seq[i].second && seq[i-1].second==1){
                tmp = seq[i-1];
                seq[i-1] = seq[i];
                seq[i] = tmp;
                i++;
            }
        }
    }
   for(int i=0; i<n1+n2; ++i){
        cout << seq[i].first;
    }
    return 0;
}