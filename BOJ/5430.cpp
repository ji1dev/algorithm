// 5430번_AC
#include <iostream>
#include <string>
#include <deque>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    int t, n, len;
    bool rflag, errflag;
    string p, x, tmp;
    deque <int> dq;
    F_I;
    cin >> t;
    while(t--){
        dq.clear(); // 덱 초기화
        rflag = errflag = false; // reverse, error flag
        cin >> p >> n >> x;
        len = x.length();
        // 입력 배열에서 숫자만 파싱 (여러 자리 정수도 입력될 수 있음)
        for(int i=0; i<len ;++i){
            if(x[i]>='0' && x[i]<='9') tmp += x[i];
            else if(x[i]==',' || x[i]==']'){
                if(!tmp.empty()){ // 입력 배열에 숫자가 없으면 stoi를 수행하지 않음
                    dq.push_back(stoi(tmp));
                    tmp.clear();
                }
            }
        }
        len = p.length();
        for(int i=0; i<len; ++i){
            if(p[i] == 'R') rflag = rflag?false:true; // 'R'함수 들어오면 rflag toggle
            if(p[i] == 'D'){
                if(!dq.empty()){
                    if(rflag) dq.pop_back(); // rflag 활성화 되어있으면 reverse상태, 뒤에서 pop
                    else dq.pop_front(); // 아니면 앞에서 pop
                }
                else{
                    cout << "error\n";
                    errflag = true; // 덱 비어있으면 error flag활성화, break
                    break;
                }
            }
        }
        if(!errflag){
            cout << "[";
            for(int i=0; i<dq.size(); ++i){
                if(rflag) cout << dq[dq.size()-1-i]; // rflag 활성화 되어있으면 뒤에서부터 출력
                else cout << dq[i];
                if(i != dq.size()-1) cout << ",";
            }
            cout << "]\n";
        }
    }
    return 0;
}