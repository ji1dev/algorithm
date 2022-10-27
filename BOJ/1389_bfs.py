# 1389번_케빈 베이컨의 6단계 법칙
import sys
from collections import deque
input = sys.stdin.readline
n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

def bfs(start):
    q = deque()
    visited = [-1] * (n+1)
    q.append(start)
    visited[start] = 0
    while q:
        cur = q.popleft()
        for k in adj[cur]:
            if visited[k] != -1: continue
            visited[k] = visited[cur]+1 # 단계++
            q.append(k)

    # i번째 사람의 케빈 베이컨 수 계산
    cnt = 0
    for i in range(1, n+1):
        cnt += visited[i]
    
    return cnt

ans = 0
min_sum = sys.maxsize
for i in range(1, n+1):
    sum = bfs(i)
    if min_sum > sum:
        min_sum = sum
        ans = i 

print(ans)