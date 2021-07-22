// 10974번_모든 순열
// 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램
#include <iostream>
#include <vector>
using namespace std;
int n;
bool visited[9];
vector<int> seq;
void mkSeq(int len){
    if(len == n){
        for(int i=0; i<n; ++i) cout << seq[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; ++i){
        if(!visited[i]){
            visited[i] = true;
            seq.push_back(i);
            mkSeq(len+1);
            visited[i] = false;
            seq.pop_back();
        }
    }
}
int main(){
    cin >> n;
    mkSeq(0);
    return 0;
}