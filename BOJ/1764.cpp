// 1764번_듣보잡
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
    int n, m, cnt = 0;
    string tmp;
    vector<string> v1, v2, ans;
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        v1.push_back(tmp);
    }
    for(int i=0; i<m; ++i){
        cin >> tmp;
        v2.push_back(tmp);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i=0; i<m; ++i){
        int left = 0, mid, right = n-1;
        while(left <= right){
            mid = (left+right)/2;
            if(v2[i] == v1[mid]){
                ans.push_back(v2[i]);
                cnt++;
                break;
            }
            else if(v2[i] < v1[mid]) right = mid-1;
            else left = mid+1;
        }
    }
    cout << cnt << "\n";
    for(int i=0; i<ans.size(); ++i) cout << ans[i] << "\n";
    return 0;
}