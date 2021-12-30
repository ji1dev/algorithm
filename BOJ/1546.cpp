// 1546번_평균
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, score[1000], mx;
    float tmp = 0;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> score[i];
    }
    sort(score, score+n);
    mx = score[n-1];
    for(int i=0; i<n; ++i){
        tmp += (float)score[i]/mx*100;
    } 
    cout << tmp/n;
    return 0;
}