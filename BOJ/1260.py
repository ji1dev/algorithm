# 1260번_DFS와 BFS
from collections import deque
import sys
input = sys.stdin.readline
n, m, v = map(int, input().split())
a = [[] for _ in range(n+1)]

# 양방향 간선 정보 입력
for _ in range(m):
    s, e = map(int, input().split())
    a[s].append(e)
    a[e].append(s)

# 정점 번호가 작은 것을 먼저 방문해야되므로 정렬
for i in range(1, n+1):
    a[i].sort()

# DFS
def dfs(v):
    print(v, end=' ')
    visited[v] = True
    for i in a[v]: # 정점 v와 연결된 정점 중 방문하지 않은 곳 방문
        if not visited[i]:
            dfs(i)

visited = [False] * (n+1)
dfs(v) # 시작 정점 v
print('')

# BFS
def bfs(v):
    q = deque()
    visited[v] = True
    q.append(v)
    while q:
        cur = q.popleft() # 큐에서 정점을 하나 꺼냄
        print(cur, end=' ')
        for i in a[cur]:
            if visited[i]: continue
            visited[i] = True
            q.append(i) # cur의 이웃 노드 중 방문하지 않은 곳 방문

visited = [False] * (n+1) # 방문 배열 초기화
bfs(v)