# 1167번_트리의 지름
from collections import deque
import sys
input = sys.stdin.readline
v = int(input()) # 트리의 정점 개수

# 간선의 정보 입력 (a에서 b까지 거리 c 형태)
arr = [[] for _ in range(v+1)]
for _ in range(v):
    tmp = list(map(int, input().split()))
    a = tmp[0] # 출발 정점 번호
    idx = 1
    while True:
        b = tmp[idx]
        idx += 1
        
        # -1이면 입력 끝
        if b == -1: break
        c = tmp[idx]
        idx += 1

        # a->b 거리 c, b->a 거리 c 정보를 저장
        arr[a].append((b, c))
        arr[b].append((a, c))

# BFS
def bfs(i):
    q = deque()
    visited[i] = -1 # 시작 정점 재방문 안되도록 0 아닌 값으로 설정
    q.append(i)
    while q:
        cur = q.popleft()
        for next in arr[cur]:
            # 방문 배열 값 0 아니면 이미 방문한 적 있는 정점이므로 넘어감
            if visited[next[0]] != 0: continue
            visited[next[0]] = visited[cur]+next[1] # 현재 이동 거리 + 다음 노드까지 거리
            q.append(next[0])

visited = [0] * (v+1) # 이동 거리를 저장하는 방문 배열
bfs(1) # 1번 정점에서 BFS시작

# 1번 정점에서 가장 멀리 있는 정점을 찾음
maxd = 0
maxv = 0
for i in range(2, v+1):
    if maxd < visited[i]:
        maxd = visited[i]
        maxv = i

visited = [0] * (v+1) # 방문 배열 초기화
bfs(maxv) # maxv 정점에서 BFS 시작
visited.sort()
print(visited[v]+1) # maxv 정점에서 가장 멀리 떨어진 정점까지의 거리