// 14226번_이모티콘
#include <iostream>
#include <queue>
#define MP make_pair
using namespace std;
int s;
bool visited[1001][1001]; // 이모티콘 개수, 클립보드에 복사된 이모티콘 개수
queue< pair< pair<int, int>, int > > q;
void bfs(){
    visited[1][0] = true;
    q.push(MP(MP(1, 0), 0)); // 이모티콘 개수, 클립보드에 복사된 이모티콘 개수, 소요 시간
    while(!q.empty()){
        int cnt = q.front().first.first;
        int clip = q.front().first.second;  // 2, 3번 연산시 clip은 그대로 유지되고 cnt만 바뀜
        int sec = q.front().second;
        q.pop();
        if(cnt == s){
            cout << sec << "\n";
            return;
        }
        if(cnt>0){ // 1, 3번 연산시 화면에 있는 이모티콘 1개 이상 필요
            // 1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장
            if(!visited[cnt][cnt]){
                visited[cnt][cnt] = true;
                q.push(MP(MP(cnt, cnt), sec+1));
            }
            // 3. 화면에 있는 이모티콘 중 하나를 삭제
            if(!visited[cnt-1][clip]){
                visited[cnt-1][clip] = true;
                q.push(MP(MP(cnt-1, clip), sec+1));
            }
        }   
        if(clip>0){ // 2번 연산시 클립보드에 있는 이모티콘 1개 이상 필요
            // 2. 클립보드에 있는 모든 이모티콘을 화면에 붙임
            if(clip>0 && cnt+clip<=s && !visited[cnt+clip][clip]){
                visited[cnt+clip][clip] = true;
                q.push(MP(MP(cnt+clip, clip), sec+1));
            }
        }   
    }
}
int main(){
    cin >> s;
    bfs();
    return 0;
}