// 1248번_맞춰봐
#include <iostream>
#include <vector>
using namespace std;
int n, r;
char s[10][10];
bool flag = false;
vector<int> ans;
bool Verify(int cnt){
    int sum = 0;
    for (int i=cnt; i>=0; --i){
        // s[cnt][cnt] ~ s[0][cnt]의 부호와 ans[cnt] ~ ans[cnt]+...+ans[0]을 비교
        // 부호가 맞지 않으면 해당 숫자를 수열에서 제거하고 다음 숫자를 넣어서 확인
        sum += ans[i];
        if((s[i][cnt] == '+') && (sum <= 0)) return false;
        if((s[i][cnt] == '0') && (sum != 0)) return false;
        if((s[i][cnt] == '-') && (sum >= 0)) return false;
    }
    return true;
}
void Solve(int cnt){
    if(flag) return;
    // 수열에 n개 수가 채워지면 원소 출력 후 종료
    if(cnt == n){
        for(int i=0; i<n; ++i) cout << ans[i] << " ";
        flag = true;
        return;
    }
    for(int i=-10; i<=10; ++i){
        ans.push_back(i);
        // 수열의 cnt번째 원소가 부호 배열의 값을 만족하는지 확인
        if(Verify(cnt)) Solve(cnt+1);
        ans.pop_back(); // 부호 조건을 만족하지 못하면 해당 원소를 제거
    }
    
}
int main(){
    cin >> n;
    // 주어지는 부호 문자열은 N(N+1)/2 길이를 가짐
    // 처음 N개 문자는 부호 배열의 첫 줄, 다음 N-1개 문자는 두 번째 줄, 마지막 문자는 N번째 줄에 해당 
    for(int i=0; i<n; ++i){
        for(int j=i; j<n; ++j){
            cin >> s[i][j];
        }
    }
    Solve(0);
    return 0;
}