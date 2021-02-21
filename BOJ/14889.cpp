// 14889번_스타트와 링크
#include <iostream>
#include <algorithm>
using namespace std;

int n, minDiff=999;
int s[21][21];
bool isBelong[21];

void BuildTeam(int num, int cnt){
    if(cnt == n/2){
        int team1 = 0, team2 = 0;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(isBelong[i] && isBelong[j]) team1 += s[i][j];
                else if(!isBelong[i] && !isBelong[j]) team2 += s[i][j];
            }
        }
        minDiff = min(minDiff, abs(team1-team2));
        return;
    }

    for(int i=num; i<=n; ++i){
        if(!isBelong[i]){
            isBelong[i] = true;
            cnt++;
            BuildTeam(i+1, cnt);
            isBelong[i] = false;
            cnt--;
        }
    }
}
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin >> s[i][j];
        }
    }
    BuildTeam(1, 0);
    cout << minDiff << "\n";
    return 0;
}