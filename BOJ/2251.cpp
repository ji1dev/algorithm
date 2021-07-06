// 2251번_물통
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MP make_pair
using namespace std;
int capacity[3]; // 각 물통의 최대 용량
int src[] = {0, 0, 1, 1, 2, 2}; // src->dst 물통으로 옮기는 6가지 경우
int dst[] = {1, 2, 0, 2, 0, 1};
bool visited[201][201];
vector<int> ans;
queue< pair<int, int> > q; // 0번, 1번 통에 들어있는 물의 용량
void bfs(){
    ans.push_back(capacity[2]); // 2번 물통의 초기 상태 저장
    q.push(MP(0, 0)); // 초기값은 2번 물통에만 물이 가득 차 있는 상태
    visited[0][0] = true;
    while(!q.empty()){
        // 물의 총량은 항상 같으므로 2번 통에 들어있는 물의 용량을 구할 수 있음
        int a = q.front().first;
        int b = q.front().second;
        int c = capacity[2]-a-b;
        // printf("a:%d, b:%d, c:%d\n", a, b, c);
        q.pop();
        for(int i=0; i<6; ++i){
            int bucket[] = {a, b, c}; // 각 통에 들어있는 현재 물의 용량 배열
            int s = src[i], d = dst[i]; // 출발지, 목적지 물통 번호
            // 목적지 남은 용량에 출발지의 물을 전부 옮길 수 없는 경우
            int available = capacity[d]-bucket[d];
            if(available < bucket[s]){
                bucket[d] += available; // 목적지에 옮길 수 있는 만큼만 옮김
                bucket[s] -= available;
            }
            // 목적지의 남은 용량이 충분한 경우
            else{
                bucket[d] += bucket[s]; // 목적지는 출발지의 용량 전부를 더함
                bucket[s] = 0; // 출발지는 비워짐   
            }
            // printf("-> %d, %d, %d\n", bucket[0], bucket[1], bucket[2]);
            // 처음 시도해보는 물 용량의 조합인 경우
            if(!visited[bucket[0]][bucket[1]]){
                visited[bucket[0]][bucket[1]] = true;
                q.push(MP(bucket[0], bucket[1])); // 0번, 1번 통의 물 용량을 push
                // 0번 물통이 비어있는 경우 2번 물통의 상태를 저장
                if(bucket[0] == 0){
                    ans.push_back(bucket[2]);
                }
            }
        }
    }
}
int main(){
    for(int i=0; i<3; ++i) cin >> capacity[i];  
    bfs();
    sort(ans.begin(), ans.end()); // 2번 물통에 담겨있을 수 있는 물의 양들을 오름차순 정렬
    for(int i=0; i<ans.size(); ++i) cout << ans[i] << " ";
    return 0;
}