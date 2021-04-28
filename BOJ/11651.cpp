// 11651번_좌표 정렬하기 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector< pair<int, int> > pos(n);
    for(int i=0; i<n; ++i){
        cin >> pos[i].second >> pos[i].first;
    }
    sort(pos.begin(), pos.end());
    for(int i=0; i<n; ++i){
        cout << pos[i].second << " " << pos[i].first <<"\n";
    }
    return 0;
}