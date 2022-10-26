# 1707번_이분 그래프
import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
k = int(input())

# DFS 수행하면서 현재 그래프가 이분 그래프인지 판단
# 두 번째 인자는 현재 정점이 속한 집합을 의미 (1 or -1)
def dfs(node, group):
    visited[node] = group
    for i in a[node]: # 현재 정점과 인접한 정점들 확인
        if visited[i] == 0: # 방문 안한 인접 정점은 현재 정점과 다른 그룹에 넣음
            if not dfs(i, -group): return False 
        else: # 이미 방문한 정점이면 현재 정점과 같은 그룹인지 확인
            if visited[i] == visited[node]:
                return False # 이분 그래프 성질 만족 x

    return True # 끝까지 조건에 걸리지 않으면 각 집합에 속한 정점끼리는 서로 인접하지 않음

for _ in range(k):
    n, m = map(int, input().split()) # 정점 개수, 간선 개수
    a = [[] for _ in range(n+1)]
    for _ in range(m):
        u, v= map(int, input().split()) # 두 인접 정점의 번호
        a[u].append(v)
        a[v].append(u)
    
    flag = False # 이분 그래프가 아닌 경우 활성화

    visited = [0] * (n+1)
    for i in range(1, n+1): # 1~n번 정점에서 DFS 시작, 비연결 그래프가 존재할 수 있기 때문
        if visited[i] != 0: continue # 이미 그룹에 속한 정점은 넘어감
        if not dfs(i, 1): flag = True # 이분 그래프 아니면 flag 활성화

    if not flag: print('YES')
    else: print('NO')