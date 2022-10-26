# 2251번_물통
from collections import deque
import sys
input = sys.stdin.readline
a, b, c = map(int, input().split())
max = 201
src = [0, 0, 1, 1, 2, 2] # 물을 옮길 통
dst = [1, 2, 0, 2, 0, 1] # 물이 옮겨질 통
capa = [a, b, c] # 통의 용량
ans = []

# 3개 통에 통에 물이 담길 수 있는 경우의 수를 BFS로 확인
# 통의 크기는 고정이므로 A, B 두 통의 현재 물 양을 알면 C 통의 양은 역산 가능
def bfs():
    q = deque()
    visited = [[False for _ in range(max)] for _ in range(max)] # 방문 배열
    q.append((0, 0)) # A, B 통은 처음에 비어있음
    visited[0][0] = True
    while q:
        cur_a, cur_b = q.popleft()
        cur_c = c-(cur_a+cur_b) # C 현재 물의 양 역산
        for k in range(6):
            cur = [cur_a, cur_b, cur_c] # 6가지 이동 경우를 확인하기 위해 매번 초기화
            s = src[k]
            d = dst[k]

            # 도착 물통의 남은 용량에 따라 출발 물통에서 물을 옮김
            diff = capa[d]-cur[d]
            if diff >= cur[s]: # 남은 용량 널널하므로 전부 옮김
                cur[d] += cur[s]
                cur[s] = 0
            else: # 다 안들어가므로 일부만 옮김
                cur[s] -= diff
                cur[d] += diff

            # 처음 확인하는 물의 양 조합이면 큐에 삽입
            if visited[cur[0]][cur[1]]: continue
            visited[cur[0]][cur[1]] = True
            q.append((cur[0], cur[1])) # 새로운 물 용량 조합

            # A가 비어 있을 때, C에 담겨있는 물의 양을 저장
            if cur[0] == 0: ans.append(cur[2])
        
bfs()
ans.append(c) # C가 가득 찬 경우 추가 (초기값)
ans.sort()
print(*ans)