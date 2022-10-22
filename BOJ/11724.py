# 11724번_연결 요소의 개수
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
a = [[] for _ in range(n+1)] # 각 노드와 연결된 노드를 저장하는 리스트
visited = [False] * (n+1) # 방문 배열

def dfs(v):
    visited[v] = True
    for i in a[v]: # 노드 v와 연결된 노드들 중 방문하지 않는 노드로 진행
        if not visited[i]:
            dfs(i)

for _ in range(m):
    u, v = map(int, input().split())
    a[u].append(v)
    a[v].append(u)

cnt = 0
for i in range(1, n+1):
    if not visited[i]:
        dfs(i) # i번째 노드에서 DFS시작
        cnt += 1 # DFS 한번 돌면 연결요소 하나를 탐색한 것

print(cnt)