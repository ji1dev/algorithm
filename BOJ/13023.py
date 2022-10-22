# 13023번_ABCDE
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
arr = [[] for _ in range(n)]
visited = [False] * n
flag = False

def dfs(v, cnt):
    # 4번 타고 들어온 경우 조건에 맞는 그래프임
    global flag
    if cnt == 4:
        flag = True
        return
    
    visited[v] = True
    for u in arr[v]:
        if not visited[u]:
            dfs(u, cnt+1)
    
    visited[v] = False # 방문 처리 해제

# 인접리스트 입력
for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)

# i번 노드부터 4번 재귀적으로 타고 들어갈 수 있는지 확인 
for i in range(n):
    dfs(i, 0)
    if flag: break

if flag: print(1)
else: print(0)