# 2178번_미로 탐색
from collections import deque
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
a = [[] * m for _ in range(n)]
visited = [[0] * m for _ in range(n)] # 방문 배열, 해당 위치에 도달하기까지 밟은 칸 수 저장

# 미로 정보 입력
for i in range(n):
    tmp = list(input())
    for j in range(m):
        a[i].append(int(tmp[j]))

# BFS
di = [-1, 1, 0, 0]
dj = [0, 0, -1, 1]
def bfs(si, sj, cnt):
    q = deque()
    visited[si][sj] = 1
    q.append((si, sj))
    while q:
        cur = q.popleft()

        # 현 위치가 미로의 우하단이면 밟은 칸 수 출력하고 탈출
        if cur[0]==(n-1) and cur[1]==(m-1):
            print(visited[n-1][m-1])
            return

        # 현 위치에서 상하좌우 4방향을 확인
        for k in range(4):
            ni = cur[0]+di[k]
            nj = cur[1]+dj[k]
            # 미로 범위 벗어나거나, 방문했거나, 벽이면 넘어감
            if ni<0 or ni>=n or nj<0 or nj>=m: continue
            if a[ni][nj]==0 or visited[ni][nj]: continue
            visited[ni][nj] = visited[cur[0]][cur[1]]+1
            q.append((ni, nj))

bfs(0, 0, 1) # 좌상단에서 시작