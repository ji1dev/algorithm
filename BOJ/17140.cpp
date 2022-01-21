// 17140번_이차원 배열과 연산
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#define MAX 101
#define MP make_pair
using namespace std;
int r, c, k, ncnt[MAX], a[MAX][MAX];
vector<pair<int, int> > v;
void solve(){
    int rcnt = 3, ccnt = 3, elapsed = 0;
    while(1){
        if(a[r-1][c-1]==k || elapsed > 100) break;
        if(rcnt >= ccnt){ // R연산
            for(int i=0; i<rcnt; ++i){
                for(int j=0; j<ccnt; ++j){
                    ncnt[a[i][j]]++; // 원소별 개수 count
                    a[i][j] = 0; // 이전 원소 개수보다 적은 원소가 덮어씌워질 수 있으므로 0으로 초기화
                }
                for(int j=1; j<MAX; ++j){ // 원소별 개수와 해당 원소 저장
                    if(ncnt[j]) v.push_back(MP(ncnt[j], j));
                }
                sort(v.begin(), v.end()); // 원소별 개수 오름차순 정렬, 동순위면 원소 값 기준
                for(int j=0, p=0; p<v.size(); ++p){
                    a[i][j++] = v[p].second; // 원소 값, 개수 순서로 배열 갱신
                    a[i][j++] = v[p].first;
                }
                ccnt = max(ccnt, (int)v.size()*2); // 열 크기 늘어난 값으로 갱신
                memset(ncnt, 0, sizeof(ncnt));
                v.clear();
            }
        }
        else{ // C연산
            for(int j=0; j<ccnt; ++j){
                for(int i=0; i<rcnt; ++i){
                    ncnt[a[i][j]]++;
                    a[i][j] = 0;
                }
                for(int i=1; i<MAX; ++i){
                    if(ncnt[i]) v.push_back(MP(ncnt[i], i));
                }
                sort(v.begin(), v.end());
                for(int i=0, p=0; p<v.size(); ++p){
                    a[i++][j] = v[p].second;
                    a[i++][j] = v[p].first;
                }
                rcnt = max(rcnt, (int)v.size()*2); // 행 크기 늘어난 값으로 갱신
                memset(ncnt, 0, sizeof(ncnt));
                v.clear();
            }
        }
        elapsed++;
    }
    cout << (elapsed<=100 ? elapsed : -1);
}
int main(){
    cin >> r >> c >> k;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            cin >> a[i][j];
        }
    }
    solve();
    return 0;
}