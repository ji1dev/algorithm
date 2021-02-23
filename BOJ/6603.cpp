// 6603번_로또
#include <iostream>
using namespace std;
int k, s[12], ans[6];
bool isUsed[12];

void Lottery(int idx){
    if(idx == 6){
        for(int i=0; i<6; ++i){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    for(int i=0; i<k; ++i){
        if(!isUsed[i]){
            // 사전 순으로 수를 고르기 위한 조건
            if(idx == 0 || ans[idx-1] < s[i]){
                isUsed[i] = true;
                ans[idx] = s[i];
                Lottery(idx+1);
                isUsed[i] = false;
            } 
        }
    }
}

int main(){
    while(1){
        cin >> k;
        if(!k) break;
        for(int i=0; i<k; ++i) cin >> s[i];
        Lottery(0);
        cout << "\n";
    }
    return 0;
}