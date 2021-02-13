// 2605번_줄 세우기
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> line;
    int n, select;
    cin >> n;
    for(int i=1; i<=n; ++i){
        // 두 번째 학생부터는 뽑은 번호만큼 앞으로 가서 줄을 섬
        cin >> select;
        if(line.empty()) line.push_back(i);
        else line.insert(line.end() - select, i);
    }
    for(int i=0; i<n; ++i){
        cout << line[i] << " ";
    }
    return 0;
}