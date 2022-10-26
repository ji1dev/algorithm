# 18352번_특정 거리의 도시 찾기
from collections import deque
import sys
input = sys.stdin.readline
n, m, k, x = map(int, input().split()) # 도시 수, 도로 수, 거리 정보, 출발 도시 번호
v = [[] for _ in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    v[a].append(b)

# BFS로 최단거리 K에 위치한 모든 도시의 번호를 구함
visited = [False] * (n+1)
ans = []
def bfs(start):
    q = deque()
    visited[start] = True
    q.append((start, 0)) # 도시 번호, 이동 거리
    while q:
        cur = q.popleft()
        if cur[1] == k: # 이동 거리 k인 도시 찾으면 번호를 저장
            ans.append(cur[0])
        for next in v[cur[0]]:
            if visited[next]: continue
            visited[next] = True
            q.append((next, cur[1]+1)) # 도시 간 거리는 모두 1

bfs(x)
ans.sort()
if not ans: print(-1)
else:
    for i in ans: print(i)