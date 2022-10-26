# 1325번_효율적인 해킹
import sys
from collections import deque
input = sys.stdin.readline
n, m = map(int, input().split())
v = [[] for _ in range(n+1)]

# A가 B를 신뢰하면 B를 통해 A를 해킹할 수 있으므로 B->A 단방향 그래프
for _ in range(m):
    a, b = map(int, input().split())
    v[b].append(a)

# BFS로 시작 노드에서 갈 수 있는 거리를 구함
def bfs(start):
    q = deque()
    visited = [False] * (n+1)
    visited[start] = True
    q.append(start)
    cnt = 1 # 해킹한 컴퓨터 수
    while q:
        cur = q.popleft()
        for i in v[cur]:
            if visited[i]: continue
            visited[i] = True
            q.append(i)
            cnt += 1
    return cnt

ans = [0] # 인덱스 1부터
for i in range(1, n+1): # 컴퓨터 1~N번
    ans.append(bfs(i)) # i번 노드에서 출발

max = max(ans)
for i in range(1, n+1):
    if ans[i] == max: print(i, end=' ')