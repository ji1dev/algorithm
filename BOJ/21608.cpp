// 21608번_상어 초등학교
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Pos{
    // 앉을 자리 좌표, 인접 빈 칸 개수, 인접 좋아하는 친구 수
    int r, c, ec, fc;
    Pos(int r, int c, int ec, int fc): r(r), c(c), ec(ec), fc(fc){};
    // overloading greater than operator (16236번 참고)
    bool operator < (const Pos &p) const{
        if(fc == p.fc){ // 조건1 만족하는 칸 여러개인 경우
            if(ec == p.ec){ // 조건2 만족하는 칸 여러개인 경우
               if(r == p.r) return c > p.c; // 조건3. 열 번호 가장 작은 칸 선택
               else return r > p.r; // 조건3. 행 번호 가장 작은 칸 선택 
            }
            else return ec < p.ec; // 조건2. 빈 칸 가장 많이 인접하는 칸 선택
        }
        else return fc < p.fc; // 조건1. 좋아하는 학생 가장 많이 인접하는 칸 선택
    }
};
struct Student{
    int r, c, num, fav[4];
};
int n, ans, map[20][20] = {0, };
int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1}; // 상, 하, 좌, 우
int satisfied[] = {0, 1, 10, 100, 1000};
int main(){
    cin >> n;
    vector< Student > v(n*n);
    for(int i=0; i<n*n; ++i){
        cin >> v[i].num; // 학생 번호
        for(int j=0; j<4; ++j){
            cin >> v[i].fav[j]; // 좋아하는 학생 4명 번호
        }
    }
    // 조건에 따라 학생들의 자리를 배치함
    for(int k=0; k<n*n; ++k){
        priority_queue< Pos > pq;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                int ec = 0, fc = 0; // 인접한 칸의 빈 칸 개수, 좋아하는 학생 수
                // 현재 위치가 빈 칸인 경우 ec, fc 구하기
                if(map[i][j] == 0){
                    for(int d=0; d<4; ++d){
                        int ni = i+di[d];
                        int nj = j+dj[d];
                        if(ni>=0 && ni<n && nj>=0 && nj<n){
                            if(map[ni][nj] == 0) ec++; // 빈 칸 count
                            else{ 
                                // k번째 학생이 좋아하는 학생 count
                                for(int f=0; f<4; ++f){
                                    if(map[ni][nj] == v[k].fav[f]){
                                        fc++;
                                        break; // 만족하는 값 찾으면 나머지 볼 필요 없음
                                    }
                                }
                            } 
                        }
                    }
                    //printf("[push] %d,%d / ec:%d, fc:%d\n", i, j, ec, fc);
                    pq.push(Pos(i, j, ec, fc)); // 우선순위 큐에 배치 위치 후보 push
                }
                
            }
        }
        if(!pq.empty()){
            // 후보들 중 조건에 부합하는 위치에 실제 학생을 배치
            // 조건 부합하는 위치 == 우선순위 큐의 top에 포함된 r, c값
            int r = pq.top().r;
            int c = pq.top().c;
            map[r][c] = v[k].num;
            v[k].r = r;
            v[k].c = c;
            //printf("[save] %d,%d\n", r, c);
        }
    }
    // 학생의 만족도 총합 계산
    for(int k=0; k<n*n; ++k){
        int cnt = 0;
        int i = v[k].r;
        int j = v[k].c;
        // 각 학생별 인접 자리에 좋아하는 학생이 몇 명 있는지 count
        for(int d=0; d<4; ++d){
            int ni = i+di[d];
            int nj = j+dj[d];
            if(ni>=0 && ni<n && nj>=0 && nj<n){
                for(int f=0; f<4; ++f){
                    if(map[ni][nj] == v[k].fav[f]){
                        cnt++;
                        break;
                    }
                }
            }
        }
        ans += satisfied[cnt]; // 좋아하는 학생 수 만큼 만족도++
    }
    // for(int i=0; i<n; ++i){
    //     for(int j=0; j<n; ++j){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << ans;
    return 0;
}